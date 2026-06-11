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

int n; cin >> n;
vi v(n); rep(i,n) cin >> v[i];

map<int, int> mp1, mp2;
for(int i = 0; i < n; i += 2) mp1[v[i]]++;
for(int i = 1; i < n; i += 2) mp2[v[i]]++;

int MAX_mp1 = 0;
int o;
for(auto x : mp1) {
    if (chmax(MAX_mp1, x.second)) {
        o = x.first;
    }
}
int MAX2_mp1 = 0;
for(auto x : mp1) {
    if(x.first == o) continue;
    chmax(MAX2_mp1, x.second);
}

int MAX_mp2 = 0;
int e;
for(auto x : mp2) {
    if (chmax(MAX_mp2, x.second)) {
        e = x.first;
    }
}
int MAX2_mp2 = 0;
for(auto x : mp2) {
    if(x.first == e) continue;
    chmax(MAX2_mp2, x.second);
}

if(o != e) cout << n - MAX_mp1 - MAX_mp2 << endl;
else {
    cout << n - max((MAX_mp1 + MAX2_mp2) ,(MAX2_mp1 + MAX_mp2)) << endl;
}

return 0;
}