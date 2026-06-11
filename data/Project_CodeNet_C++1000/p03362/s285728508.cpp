#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()

int main(){
  int N;
  cin>>N;
  VI ans;
  rep(i,6000){
    int X=(i+1)*10+1;
    int F=1;
    rep(j,sqrt(X)){
      if(X%(j+2)==0){
        F=0;
        break;
      }
    }
    if(F) ans.push_back(X);
  }
  rep(i,N){
    if(i) cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;
}