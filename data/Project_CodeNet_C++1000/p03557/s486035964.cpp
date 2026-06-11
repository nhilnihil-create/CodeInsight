#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define all(x) (x).begin(), (x).end()
#define len(x) ((long long)(x).size())
#define srt(x) sort((x).begin(), (x).end())
#define rsrt(x) sort((x).rbegin(), (x).rend())
#define g(a, b) __gcd((a), (b))
#define l(a, b) ((a) / __gcd((a), (b)) * (b))
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<long long>;
using vllvll = vector<vll>;
using vc = vector<char>;
using vs = vector<string>;
using um = unordered_map<long long, long long>;
template<class T>void print(T x) { cout << '\n' << "== " << x << " ==" << '\n'; }
template<class T>void print1d(T x,ll n=-1){if(n==-1)n=x.size();rep(i,0,n){cout<<x[i]<<' ';}cout<<'\n';}
template<class T>void print2d(T x,ll r=-1,ll c=-1){if(r==-1)r=x.size();if(c==-1)c=x[0].size();rep(i,0,r)print1d(x[i],c);}
template<class T>void precise(T x) { cout << setprecision(21) << x << '\n'; }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<class T, class U>T rem(T a, U b) { return a - b*floor(a/b); }
template<class T>ld deg2rad(T deg) { return M_PI * deg / 180.0; }
template<class T>ld rad2deg(T rad) { return 180.0 * rad / M_PI; }
const long double pi = M_PI;
const long double doublepi = M_PI * 2.0;
const long double halfpi = M_PI / 2.0;
const long long big = 1LL << 50;
const long long inf = 1LL << 60;
const long long MOD = 1e9 + 7;




int main()
{
    ll N;
    cin >> N;
    vll A(N), B(N), C(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    rep(i, 0, N) cin >> C[i];
    srt(A); srt(B); srt(C);
    //rep (i, 0, N) cout << A[i] << ' ';
    ll acnt, bcnt, ccnt;
    ll bel;
    ll tmp;
    ll s = 0;
    rep(i, 0, N) {
        bel = B[i];
        tmp = lower_bound(A.begin(), A.end(), bel) - A.begin();
        acnt = tmp;
        //if (tmp >= N) acnt = 0;
        tmp = upper_bound(C.begin(), C.end(), bel) - C.begin();
        ccnt = N - tmp;
        //if (tmp >= N) ccnt = 0;
        s += acnt * ccnt;
    }
    cout << s << endl;

}