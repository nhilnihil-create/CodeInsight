/* ID: thanhvq1
LANG: C++14
PROB: namenum
*/

#pragma GCC optimize ("O2")
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

// defines
#define int long long
typedef long long ll;
//#define double long double
#define vec vector
#define vi vector<int>
#define vvi vector<vector<int>>
#define unset unordered_set
#define ii pair<int, int>
#define vii vector<ii>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(x) begin(x),end(x)
#define SZ(x) ((int)(x).size())
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define bitcount(n) __builtin_popcountll(n)
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).resize(unique((x).begin(), (x).end()) - (x).end());
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define debug(x) cout << #x << " = " << (x) << endl
#define debug2(x, y) cout<<#x<<" = "<<(x)<<", "<<#y<<" = "<<(y)<< endl
#define debug3(x, y, z) cout<<#x<<" = "<<(x)<<", "<<#y<<" = "<<(y)<<", "<<#z<<" = "<<(z)<<endl
void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)

//permanent constants
const long long INF64 = 1e18; const int INF32 = 1e9; const int BIG = (int)(1e9 + 239);
//const int MOD = 998244353; //1e9 + 7;  const ll MOD2 = (ll)MOD * (ll)MOD;
const double PI = 2.0*acos(0.0); //acos(-1.0L);
const double EPS = static_cast<double>(1e-10);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dx[4] = {0, 1, 0, -1}; const int dy[4] = {1, 0, -1, 0};
//const ll INF = (ll)(1e18 + 239);

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

/*GRAPH:
 * 	const int INF = 1e9 + 5;
 	int N; cin >> N;
	vector<vector<int>> dist; // ma tran dist giua cac dinh
    dist.assign(N, vector<int>(N, INF)); // Khoi tao ma tran dist bang INF
 */
// Sort w Lambda Function: sort(begin(v), end(v), [] (int a, int b) { return a > b; });

void FILEIO() {  freopen("in.txt", "r", stdin);  freopen("out.txt", "w", stdout); }
//void FILEIO()   {freopen("in.txt", "w", stdout);}
//void FILEIO() {  freopen("namenum.in", "r", stdin);  freopen("namenum.out", "w", stdout); }

// Init variables here

void solve() {
	int n; string s; cin >> n >> s;
	int r=0, b=0;
	FOR(i, 0, n) {if(s[i]=='R') r++; else b++;}
	if(r>b) cout << "Yes" << endl; else cout << "No" << endl;
}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie();
//  FILEIO();
//  auto beginProgram = chrono::steady_clock::now();

//  int t; cin >> t;
//  while(t--)
  {
//	  input();
	  solve();
  }

//  auto endProgram = chrono::steady_clock::now();
//  cout << chrono::duration_cast<chrono::milliseconds>(endProgram - beginProgram).count() << " ms" << endl;

  return 0;
}
