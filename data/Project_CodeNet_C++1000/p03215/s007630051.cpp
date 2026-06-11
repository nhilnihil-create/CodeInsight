#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  int n,k;
  cin >> n >> k;
  ll a[n+1];
  a[0]=0;
  for(int i=0;i<n;i++)cin >> a[i+1];
  ll sum[n+1]={};
  sum[0]=0;
  vector<ll> v;
  for(int i=0;i<n;i++)sum[i+1]=sum[i]+a[i+1];
  for(int i=1;i<=n;i++){
    for(int j=0;j<=i-1;j++){
      v.push_back(sum[i]-sum[j]);
    }
  }
  ll ans=0;
  vector<ll> temp;
  for(int i=40;i>=0;i--){
    int cnt=0;
    temp.clear();
    for(int j=0;j<v.size();j++){
      if (v[j] & (1ll<<i)){
        cnt++;
        temp.push_back(v[j]);
      }
    }
    if(cnt>=k){
      ans+=(1ll<<i);
      v.swap(temp);
    }
  }
  cout << ans << endl;
  return 0;
}