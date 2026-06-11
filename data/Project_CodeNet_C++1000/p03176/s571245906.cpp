#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;


struct SegTree {
  vector<ll> st;
  int n;
  ll neutro = 0;

  SegTree(int _n){
    n = _n;
    st.assign(n << 2, neutro);
  }

  ll query(int i, int j) { return query(1, 0, n-1, i, j); }

  ll query(int p, int L, int R, int i, int j){
    if(i > R || j < L)return neutro;
    if(i <= L && j >= R)return st[p];
    int m = (L+R)/2, l = p*2, r = l+1;
    ll a = query(l, L, m, i, j);
    ll b = query(r, m+1, R, i, j);
    return max(a, b);
  }

  void update(int i, ll val) { update(1, 0, n-1, i, val); }

  void update(int p, int L, int R, int i, ll val){
    if(i > R || i < L)return;
    if(L == R)st[p] = val;
    else{
      int m = (L+R)/2, l = p*2, r = l+1;
      update(l, L, m, i, val);
      update(r, m+1, R, i, val);
      st[p] = max(st[l], st[r]);
    }
  }

};


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  vector<int> h(n), a(n);
  int mx = 0;
  forn(i, 0, n){
    cin >> h[i];
    mx = max(mx, h[i]);
  }
  forn(i, 0, n)cin >> a[i];

  SegTree st(mx+1);

  ll ans = 0;
  forn(i, 0, n){
    ll x = st.query(0, h[i]-1);
    ll y = st.query(h[i], h[i]);
    if(y < x+a[i]){
      st.update(h[i], x+a[i]);
      ans = max(ans, x+a[i]);
    }
  }

  cout << ans << endl;



}



