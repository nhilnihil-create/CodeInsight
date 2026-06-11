#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main(){
  int D, G;
  cin >> D >> G;
  vector<int> p(D), c(D);
  for(int i=0; i<D; i++){
    cin >> p.at(i) >> c.at(i);
  }
  int ans = 1000;
  for(int tmp=0; tmp<(1<<10); tmp++){
    bitset<10> s(tmp);
    int score = 0, num = 0, index = 0;
    for(int i=0; i<D; i++){
      if(s.test(i)){
        score += 100*(i+1)*p.at(i)+c.at(i);
        num += p.at(i);
      }else{
        index = max(index, i);
      }
    }
    int m = 0;
    while(score<G){
      score += 100*(index+1);
      m++;
    }
    if(m>=p.at(index)){
      continue;
    }else{
      num += m;
    }
    ans = min(ans, num);
  }
  cout << ans;
  return 0;
}