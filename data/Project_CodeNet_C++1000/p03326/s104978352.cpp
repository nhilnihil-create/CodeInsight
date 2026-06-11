#include <bits/stdc++.h> 

using namespace std; //ごめんなさい
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define rep(i,N) for(int i=0;i<N;i++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N,M;
  cin>>N>>M;
  vector<ll>x(N),y(N),z(N);
  for(int i=0;i<N;i++)cin>>x[i]>>y[i]>>z[i];
  int B=pow(2,3);
  ll ans=0;
  for(int bit=0;bit<B;bit++){
    vector<int>a(3);
    for(int i=0;i<3;i++){
      if((bit>>i)&1)a[i]=1;
      else a[i]=-1;
    }
    vector<ll>X(N);
    for(int i=0;i<N;i++)X[i]=a[0]*x[i]+a[1]*y[i]+a[2]*z[i];
    sort(rng(X));
    reverse(rng(X));
    ll res=0;
    for(int i=0;i<M;i++)res+=X[i];
    ans=max(ans,res);
  }
  cout<<ans<<endl;
  return 0;
}
