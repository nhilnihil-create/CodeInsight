#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define countof(array) (sizeof(array) / sizeof(array[0]))
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define rep2(i,n) for(int i = 1; i <= (n); ++i)
#define rrep2(i,n) for(int i = (n); i > 0; --i)
#define srep(i,s,n) for(int i = s; i < (n); ++i)
#define rsrep(i,s,n) for(int i = (n)-1; i >= s; --i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define aall(a) (a), (a)+countof(a)//for array sorting
#define raall(a) (a), (a)+countof(a), greater<>()
#define show(x) cout<<#x<<" = "<<(x)<<endl;
#define vfind(v, a) find(all(v), a) != v.end()
#define yn(f) { if (f) puts("YES"); else puts("NO"); }
#define yns(f) { if (f) puts("Yes"); else puts("No"); }
#define show_ary(...) { cout<<#__VA_ARGS__<<" = "; for (const auto& x : (__VA_ARGS__)) { cout<<x<<" "; } cout<<endl; }
#define show_pair(...) cout<<#__VA_ARGS__<<" = "<<endl; for (const auto& x : (__VA_ARGS__)) { cout<<"  "<<x.fi<<" : "<<x.se<<endl; }
#define out_ary(...) { int n = (__VA_ARGS__).size(); rep(i, n) printf("%d%s", (__VA_ARGS__)[i], i != n-1 ? " " : "\n"); }
#define argmax(v) distance((v).begin(), max_element(all(v)))
#define argmin(v) distance((v).begin(), min_element(all(v)))
#define vmax(v) *max_element(all(v))
#define vmin(v) *min_element(all(v))
typedef long long int ll;
typedef pair<int, int> P;
typedef vector<P> vpair;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<double> vdouble;
typedef vector<string> vstr;
typedef vector<bool> vbool;
typedef vector<vint> vvint;
typedef vector<vll> vvll;
typedef vector<vstr> vvstr;
typedef vector<vbool> vvbool;
const ll LINF = 2000000000000000000ll;
const int INF = 1000000100;
const ll MOD = 1e9+7;

struct mint {
    ll x;
    mint(ll x=0):x(x%MOD){}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
};

int main() {
    int n;
    string s;
    cin >> n >> s;
    sort(all(s));

    vpair rl;
    rl.emplace_back(s[0], 2);
    srep(i, 1, n) {
        if (s[i] == rl.back().fi) rl.back().se++;
        else rl.emplace_back(s[i], 2);
    }

    mint ans = 1;
    for (auto x : rl) {
        ans *= x.se;
    }

    cout << ans.x-1 << endl;
    return 0;
}