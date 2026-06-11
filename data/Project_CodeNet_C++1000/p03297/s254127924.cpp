//新幹線からAC

#include <bits/stdc++.h>
using namespace std;
    
#define int long long
#define pb push_back
#define ub upper_bound
#define lb upper_bound
#define mp make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define rep(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define ve vector
#define vi vector<int>
#define vp vector<pair<int,int>>
#define vvi vector<vector<int>>
    
using ll = long long;
const ll INF = LLONG_MAX / 4 - 100;
ll mod = 1e9 + 7;
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
vector<ll> prime;
    
class fact {
public:
    int fmod = 1e9+7;
    vector<int> fac, inv;
    fact (int n, int Mod = 1e9+7) {
        fmod = Mod;
        fac = vector<int>(n,0);
        inv = vector<int>(n,0);
        fac[0] = 1; for (int i = 1; i < n; i++) fac[i] = fac[i-1] * i % fmod;
        for (int i = 0;i < n;i++) inv[i] = fact::POW(fac[i],fmod-2);
    }
    ll nCr(ll n, ll r) {return (fac[n] * inv[r] % fmod) * inv[n-r] % fmod;}
    ll POW(ll a, ll b) {ll c = 1; while (b > 0) {if (b & 1) {c = a * c%fmod;}a = a * a%fmod; b >>= 1;}return c;}
};
    
template <class T = ll> T in() {T x; cin >> x; return (x);}
void DEBUG(vector<int> a) {for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<endl;}
void EMP(int x) {cout<<"!!!"<<x<<"!!!"<<endl;}
ll GCD(ll a, ll b) {ll c; while (b != 0) {c = a % b; a = b; b = c;}return a;}
ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;}
ll POW(ll a, ll b) {ll c = 1; while (b > 0) {if (b & 1) {c = a * c%mod;}a = a * a%mod; b >>= 1;}return c;}
void PRI(ll n) {bool a[n + 1LL]; for (int i = 0; i < n + 1LL; i++) {a[i] = 1LL;}for (int i = 2; i < n + 1LL; i++) {if (a[i]) {prime.pb(i); ll b = i; while (b <= n) {a[b] = 0; b += i;}}}}
template <typename T> T chmin(T& a, T b) {if(a>b)a=b;return a;}
template <typename T> T chmax(T& a, T b) {if(a<b)a=b;return b;}
bool isSqrt(ll a) {return pow(sqrt(a),2) == a ? 1 : 0;}
void YesNo(bool a) {if (a) cout << "Yes"; else cout << "No"; cout << endl;}
void yesno(bool a) {if (a) cout << "yes"; else cout << "no"; cout << endl;}
void YESNO(bool a) {if (a) cout << "YES"; else cout << "NO"; cout << endl;}

bool solve() {
    int t; cin >> t;
    int A[t], B[t], C[t], D[t];
    rep (i, t) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    rep (i, t) {
        int a, b, c, d;
        a = A[i], b = B[i], c = C[i], d = D[i];
        if (a < b || d < b) {
            cout << "No" << endl;
            continue;
        }
        if (c >= b) {
            cout << "Yes" << endl;
            continue;
        }
        a -= b;
        a -= (b * (max(0ll, a - c) / b));
        if (a > c) a -= b;
        if (a < 0) {
            // cout << "dasai" << endl;
            cout << "No" << endl;
            continue;
        }
        if (d == b) {
            cout << "Yes" << endl;
            continue;
        }
        if (d - b < b - c) {
            cout << "No" << endl;
            continue;
        }
        int sa = c - a;
        int hoge = a + (sa / (d - b) + 1) * (d - b);
        hoge -= c;
        int hera = b % (d - b);
        int kaisu = (d - b) / GCD(d - b, hera);
        int haba = (d - b) / kaisu;
        if ((hoge - b + c) / haba == (hoge - 1) / haba) {
            cout << "Yes" << endl;
        } else {
            // cout << "damedayo" << endl;
            cout << "No" << endl;
        }
        // DEBUG({hoge, hera, kaisu, haba});
    }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();    
}
