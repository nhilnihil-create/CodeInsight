#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define fi first
#define se second
#define inf (INT_MAX/2-1)
#define infl (1LL<<60)
#define vi vector<int>
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) begin(a),end(a)
#define y0 y5656
#define y1 y7878
#define aaa system("pause");
#define dbg(x) cerr<<(#x)<<": "<<(x)<<'\n',aaa
#define dbga(x,n) cerr<<(#x)<<"[]: ";for(int _=0;_<n;_++)cerr<<x[_]<<' ';cerr<<'\n',aaa
#define dbgs(x) cerr<<(#x)<<"[stl]: ";for(int _:x)cerr<<_<<' ';cerr<<'\n',aaa
#define dbgp(x) cerr<<(#x)<<": "<<x.fi<<' '<<x.se<<'\n',aaa
#define maxn 1000
#define maxw 10000

using namespace std;

struct yes { int w, s, p; };

yes v[maxn+5];
ll d[2*maxw+5]; ///d[w]=profit maxim pt un turn de greutate w

void umax (ll &a, ll b) { a = max(a,b); }

int main () {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int i, j, z;
  for (i = 1; i <= n; i++) cin >> v[i].w >> v[i].s >> v[i].p;
  sort (v+1,v+n+1, [](yes a, yes b) { return a.w+a.s < b.w+b.s; } );
  ///^^^vreau sa pun bucatile cu o greuate potentiala a turnului mai mare
  ///mai aproape de fund
  fill(all(d), -infl); d[0] = 0;
  for (i = 1; i <= n; i++)
    for (z = v[i].s; z >= 0; z--) umax(d[z+v[i].w], d[z] + 1LL*v[i].p);
  cout << (*max_element(all(d)));
  return 0;
}
