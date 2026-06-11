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

string s;
cin >> s;
int n = SZ(s);

s = '0' + s;
bool ok = true;
for(int l = 0, r = n; l <= r; l++, r--) {
    if(s[l] != s[r]) {
        ok = false;
        break;
    }
}
if(!ok || s[1] != '1') {
    cout << -1 << endl;
    return 0;
}

vi vec = {0};
for(int l = 0, r = n; l <= r; l++, r--) {
    if(s[l] == '1') vec.push_back(l);
}
vec.push_back(n);
rep(i,SZ(vec)) {
    if(vec[i] == n) continue;
    for(int u = vec[i]+1; u <= vec[i+1]; u++) {
        if(u == n) continue;
        cout << vec[i]+1 << ' ' << u+1 << endl;
    }
}

return 0;
}