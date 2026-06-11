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

map<int,int> mp;
int n;
int f(int i) {
  i %= n;
  if (mp.count(i)) return mp[i];
  cout<<i<<endl;
  string res;
  cin>>res;
  if (res[0] == 'V') exit(0);
  return mp[i] = (res[0] == 'M');
}
 
int g(int i, int j) { return (j-i+n)%n;}
 
int main() {
  scanf("%d",&n);
  int l = 0, r = n/2;
  int a = f(l);
  int b = f(r);
  if ((a^b) == g(l,r)%2) {
    swap(l,r); r += n;
  }
  while (1) {
    int c = (l+r)>>1;
    if ((f(l)^f(c)) == g(l,c)%2) l = c;
    else r = c;
  }
  return 0;
}