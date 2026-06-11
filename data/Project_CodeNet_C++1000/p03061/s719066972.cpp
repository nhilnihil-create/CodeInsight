// 今日はお盆前の最終出社日です
// いい加減寝ろ

#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
vector< ll > divisor(ll n) {
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,maxi=0,f=0,mini=INF,sum=0;
    ll n;
    cin>>n;
    vector<ll> v(n);
    rep(i,n)cin>>v[i];
   // sort(all(v));
    vector<ll> l(n);
    vector<ll> r(n);
    l[0]=0;
    l[1]=v[0];
    r[n-2]=v[n-1];
    r[n-1] = 0;
    REP(i,2,n) l[i]=gcd(l[i-1],v[i-1]);
    for(ll i=n-3;i>=0;i--) r[i]=gcd(r[i+1],v[i+1]);
    
    rep(i,n){
        //cout<<l[i]<<" "<<r[i]<<endl;
        maxi=max(maxi,gcd(l[i],r[i]));
    }
    cout<<maxi<<endl;
    return 0;
}
