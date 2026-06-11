#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define yn(x, ok, ng) cout << ((x)?(ok):(ng)) << endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
int const INF = 1001001001;


int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

int n,k;
cin >> n >> k;
string s;
cin >> s;

// ランレングス圧縮(両端に0個の1を置いておく)
vector<pii> v;
if(s[0] == '0') v.push_back(make_pair(1,0));
int cnt = 1;
rep(i,n) {
    if(i == n-1) {
        v.push_back(make_pair(s[n-1] - '0', cnt));
        break;
    }
    if(s[i] == s[i+1]) cnt++;
    else {
        v.push_back(make_pair(s[i]-'0',cnt));
        cnt = 1;
    }
}
if(s[n-1] == '0') v.push_back(make_pair(1,0));

int L = SZ(v);
int m = 0; // 0の区間の個数
rep(i,L) if(v[i].first == 0) m++;

if(m <= k) {
    cout << n << endl;
    return 0;
}

// m > k の場合

vi S(L+1);
rep(i,L) S[i+1] = S[i] + v[i].second;

int ans = 0;
for(int i = 0; i + 2*k < L; i = i + 2) {
    chmax(ans, S[i+2*k+1] - S[i]);
}

cout << ans << endl;
return 0;
}