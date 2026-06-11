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
  int a,b,q;
  cin >> a>> b>> q;
  vl s(a),t(b);
  rep(i,a)cin >> s[i];
  rep(i,b)cin >> t[i];
  s.push_back(100100100100100);
  t.push_back(100100100100100);
  s.push_back(-100100100100100);
  t.push_back(-100100100100100);
  sort(rng(s));
  sort(rng(t));
  vl ds(a+2),dt(b+2);
  a+=2;b+=2;
  rep(i,a){
    int x = lower_bound(rng(t),s[i])-t.begin()-1;
    //f(x>0)if(abs(s[i] - t[x])>abs(s[i]-t[x-1])) x--;
    int y = upper_bound(rng(t),s[i])-t.begin();
    ds[i] = min(abs(s[i]-t[x]),abs(s[i]-t[y]));
    //cout<<s[i]<<":"<<ds[i]<<endl;
  }
  rep(i,b){
    int x = lower_bound(rng(s),t[i])-s.begin()-1;
    //if(x>0)if(abs(t[i] - s[x])>abs(t[i]-s[x-1])) x--;
    int y = upper_bound(rng(s),t[i])-s.begin();
    dt[i] = min(abs(t[i]-s[x]),abs(t[i]-s[y]));
    //cout<<t[i]<<":"<<dt[i]<<endl;
  }
  vl ans;
  rep(i,q){
    ll c;
    cin >> c;
    ll cost = 0;
    int x = lower_bound(rng(t),c)-t.begin()-1;
    int y = upper_bound(rng(t),c)-t.begin();
    //if(x>0)if(abs(c - t[x])>abs(c-t[x-1])) x--;
    cost = min(abs(c-t[x])+dt[x],abs(c-t[y])+dt[y]);

    x = lower_bound(rng(s),c)-s.begin()-1;
    y = upper_bound(rng(s),c)-s.begin();
    //if(x>0)if(abs(c - s[x])>abs(c-s[x-1])) x--;
    cost = min(cost,min(abs(c-s[x])+ds[x],abs(c-s[y])+ds[y]));

    ans.push_back(cost);
  }
  for(auto e : ans) print(e);
  return 0;
}