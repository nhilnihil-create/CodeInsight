#include<bits/stdc++.h>
using namespace std;
#define int long long
#ifdef LOCAL
#include<debug.h>
#else
#define db(...) 21
#endif
#define sz(a) (int)a.size()
#define found(m,x) ((m).find(x)!=(m).end())
#define uset unordered_set
#define umap unordered_map
#define a(x) x.begin(),x.end()
#define fo(i,n) for(int i=0;i<(int)n;i++)
#define Fo(i,k,n) for(int i=k;k<n?i<=(int)n:i>=(int)n;k<n?i++:i--)
#define input(v,n) fo(i,n)cin>>v[i]
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pi;

const int nax = 1e5+7;
const int mod = 1e9+7; //1e9+2667 :: 0xcf : inf, 0xc0 -inf
const int inf = numeric_limits<int> :: max() - (int)1e3;
// ===================== MANASH =================== //

vector<int> p,s;
int n;
int find( int x ) {
	if ( p[x] == x ) return x;
	else return p[x] = find(p[x]);
}
bool same( int x, int y ) {
	return find(x) == find(y);
}
void unite( int a, int b) {
	int x = find(a);
	int y = find(b);
	if ( same(x,y)) return;
	if ( s[x] > s[y] ) swap(x,y);
	p[x] = y;
	s[y] += s[x];
}
void test() {
	int m;
	cin >> n >> m;
	p.resize(n+1); s.resize(n+1,1);
	iota(a(p),0);
	vector<pi> edges;
	fo(i,m) {
		int a,b;
		cin >> a >> b;
		edges.emplace_back(a,b);
	}

	int cnt = n*(n-1)/2;
	vector<int> answers;
	while(!edges.empty()) {

		answers.push_back(cnt);
		int u,v;
		tie(u,v) = edges.back();
		edges.pop_back();
		if (!same(u,v)) {
			cnt -= s[find(u)]*s[find(v)];
			unite(u,v);
		}
	}
	reverse(a(answers));
	for( int x : answers ) cout << x << '\n';
}

signed main() {

	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	cout<<"Time Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec.\n";
	#endif

	int T = 1;
	//cin >> T;
	while(T--) {
		test();
		cout << "\n";
	}
	return 0;

}