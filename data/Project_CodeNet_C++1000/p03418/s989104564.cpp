#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

/* WA→解説
余りは1,2,3より0,1,2のほうが方針が立てやすそう
実装力
単にlong long使わないからn/b*(b-k)でオーバーフロー？
*/
int main() {
  long long n,k;
  cin>>n>>k;
  if(k==0){
    cout<<n*n<<endl;
    return 0;
  }
  long long ans=0;
  for(long long b=k+1;b<=n;++b){
    ans+=n/b*(b-k);//bで割ったあまりが0,1,2,~b-1の周期が何回あるか
    if(n%b-k+1>0) ans+=n%b-k+1;
    //cout<<n/b*(b-k)<<" "<<max(0,n%b-k+1)<<endl;
  }
  cout<<ans<<endl;
}
