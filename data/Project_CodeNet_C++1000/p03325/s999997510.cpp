#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define all(x) (x).begin(), (x).end()
#define len(x) ((long long)(x).size())
#define g(a, b) __gcd((a), (b))
#define l(a, b) ((a) / __gcd((a), (b)) * (b))
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vllvll = vector<vll>;
using pll = pair<ll, ll>;
template<class T>void print1d(T x,ll n=-1){if(n==-1)n=x.size();rep(i,0,n){cout<<x[i]<<' ';}cout<<'\n';}
template<class T>void print2d(T x,ll r=-1,ll c=-1){if(r==-1)r=x.size();if(c==-1)c=x[0].size();rep(i,0,r)print1d(x[i],c);}
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<class T, class U>T rem(T a, U b) { return a - b*floor(a/b); }
template<class T>ld deg2rad(T deg) { return M_PI * deg / 180.0; }
template<class T>ld rad2deg(T rad) { return 180.0 * rad / M_PI; }
const long double pi = M_PI;
const long long big = 1LL << 50;
const long long inf = 1LL << 60;
const long long mod = 1e9 + 7;

std::map<long long, long long> factorint(long long n)
{
    std::map<long long, long long> res;
    do {
    top:
        for (long long i = 2; i < std::sqrt(n)+10; ++i) {
            if (n % i == 0) {
                if (res.find(i) == res.end()) res[i] = 0;
                res[i]++;
                n /= i;
                goto top;
            } 
        }
        if (n != 1) res[n] = 1;
        break;
    } while (true);
    
    return res;
}

int main()
{
        ll N;
        cin >> N;
        vll a(N);
        rep(i, 0, N) cin >> a[i];
        ll ans = 0;
        rep(i, 0, N) {
                auto f = factorint(a[i]);
                if (f.find(2) != f.end()) {
                        ans += f[2];
                }
        }
        cout << ans << endl;
}