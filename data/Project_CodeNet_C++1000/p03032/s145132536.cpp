#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define print(x)cout<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;

int main() {
  int n,k;
  cin>>n>>k;
  deque<ll> q;
  rep(i,n){
    ll v;
    cin>>v;
    q.push_back(v);
  }
  
  ll ans = 0;
  rep(r,k+1){
    rep(l,k+1){
      rep(d,k+1){
        deque<ll> qq = q;
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        if((r+l)>(int)qq.size()) continue;
        if((r+l+d)>k) continue;
        // show(1);
        rep(i,r){
          pq.push(qq.front());
          qq.pop_front();
        }
        rep(i,l){
          pq.push(qq.back());
          qq.pop_back();
        }
        rep(i,d){
          if(pq.size())
          if(pq.top()<0)pq.pop();
        }
        ll tmp = 0;
        while(!pq.empty()){
          tmp+=pq.top();
          pq.pop();
        }
        // show(tmp);
        maxs(ans,tmp);
      }
    }
  }
  print(ans);
  return 0;
}