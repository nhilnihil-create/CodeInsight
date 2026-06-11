//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
#define int long long
   template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
    const int MAX =1002;
const int MOD =1000000007;

signed main(){
  int n,y;
  cin>>n>>y;y/=1000;
  for(int i=0;i<=n;i++)for(int j=0;j+i<=n;j++)if(i+5*j+10*(n-i-j)==y){
    cout<<n-i-j<<' '<<j<<' '<<i<<endl;
    return 0;
  }
  cout<<-1<<' '<<-1<<' '<<-1<<endl;
}