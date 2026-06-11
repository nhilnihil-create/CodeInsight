#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
#define pb push_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
typedef long long ll;
typedef multiset<ll> S;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll,vector<ll>,greater<ll>> SPQ;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;
bool chmin(auto &a,auto b){if(a>b){a=b;return true;}return false;}
bool chmax(auto &a,auto b){if(a<b){a=b;return true;}return false;}
int main(){
    ll n,k;cin>>n>>k;
    vector<bool> used(n+1,false);
    vector<P> p(n),v,u;
    rep(i,n)cin>>p[i].first>>p[i].second;
    sort(all(p));
    rep(i,n-1){
        if(p[i].first!=p[i+1].first)v.eb(p[i].second,p[i].first);
        else u.eb(p[i].second,p[i].first);
    }
    v.eb(p[n-1].second,p[n-1].first);
    ll ans=0;
    sort(all(u));
    reverse(all(u));
    sort(all(v));
    reverse(all(v));
    ll s=min((ll)(v.size()),k);
    vector<P> q;
    rep(i,s){
        ans+=v[i].first;
        q.eb(v[i].first,v[i].second);
    }
    int w=0;
    if(s<k){
        rep(i,k-v.size()){
            ans+=u[i].first;
            used[u[i].second]=true;
            w++;
        }
    }
    int wh=s-1;
    while(w<u.size()){
        auto t=u[w];
        while(wh>=0){
          if(used[q[wh].second])wh--;
          else break;
        }
      if(wh<0)break;
        used[t.second]=true;
        if(u[w].first-q[wh].first<s*s-(s-1)*(s-1))break;
        ans+=u[w].first-q[wh].first;
        wh--;
        w++;
        s--;
    }
    cout<<ans+s*s<<endl;
}
