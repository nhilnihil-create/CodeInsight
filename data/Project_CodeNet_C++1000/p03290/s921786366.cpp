#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <tuple>
#include <bitset>
#include <random>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;


int d,g;



 
int main() {
  cin>>d>>g;
  vector<int> p(d), c(d);
  for(int i=0;i<d;i++){
    cin>>p.at(i)>>c.at(i);
  }

  int ans=10000;
  for(int tmp=0;tmp<(1<<d);tmp++){
    bitset<10> s(tmp);/*下i桁が1なら100(i+1)点(p[i]個)を全部とく*/
    int score=0;
    int solved_number=0;
    for(int i=0;i<d;i++){
      if(s.test(i)){
        score+=100*(i+1)*p[i]+c[i];
        solved_number+=p[i];
      }
    }

    /*scoreがg以上なら終わり*/
    if(score>=g){
        ans=min(ans,solved_number);
        continue;
      }
    /*そうでないとき*/
    for(int j=0;j<d;j++){
      /*100(j+1)点を解いていないとき*/
      if(!s.test(j)){
        int a=g-score;
        int b=100*(j+1);
        int need=(a+b-1)/b;

        /*p[j]個以上必要なら終わり*/
        if(need>=p[j]){
          continue;
        }

        solved_number+=need;
        ans=min(ans,solved_number);

      }
      
    }
  }

  cout<<ans<<endl;
  return 0;
}