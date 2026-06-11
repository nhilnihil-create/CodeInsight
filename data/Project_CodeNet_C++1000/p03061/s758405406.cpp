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
    sort(all(v));
    vector<ll> w=divisor(v[0]);
    vector<ll> x=divisor(v[1]);
    set<ll> s;
    rep(i,w.size()) s.insert(w[i]);
    rep(i,x.size()) s.insert(x[i]);
    map<ll,ll> m;
    rep(i,n){
        for(auto itr=s.begin();itr!=s.end();++itr){
            if(v[i]%*itr==0) m[*itr]++;
        }
    }
    for(auto itr=s.rbegin();itr!=s.rend();++itr){
        //cout<<*itr<<endl;
        if(m[*itr]>=n-1) {
            cout<<*itr<<endl;
            return 0;
        }
    }
    return 0;
}
