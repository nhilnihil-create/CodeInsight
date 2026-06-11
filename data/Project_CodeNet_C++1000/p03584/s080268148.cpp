#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
constexpr double EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max()/2;
constexpr int MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n,k;cin>>n>>k;
    vector<P> v(n);
    for(int i=0;i<n;i++){
      ll a,b;cin>>a>>b;
      v[i]=P(a,b);
    }
    ll res=0;
    for(int i=0;i<n;i++){
      ll a=v[i].first,b=v[i].second;
      if((k | a) != k) continue;
      res += b;
    }
    for(int i=0;i<30;i++){
      if((k&(1<<i))==0) continue;
      ll num=k>>(i+1);
      num = num<<(i+1);
      num+=(1<<i)-1;
      ll tmp=0;
      for(int j=0;j<n;j++){
        ll a=v[j].first,b=v[j].second;
        if((num | a )!= num) continue;
        tmp += b;
      }
      res=max(res,tmp); 
    }
    cout<<res<<endl;
}
