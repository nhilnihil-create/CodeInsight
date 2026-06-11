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



int main()
{
        ll N;
        cin >> N;
        vector<string> S(N);
        rep(i, 0, N) cin >> S[i];
        unordered_map<char, ll> cnt;
        cnt['M'] = 0;
        cnt['A'] = 0;
        cnt['R'] = 0;
        cnt['C'] = 0;
        cnt['H'] = 0;
        rep(i, 0, N) {
                if (S[i][0] == 'M') ++cnt['M'];
                if (S[i][0] == 'A') ++cnt['A'];
                if (S[i][0] == 'R') ++cnt['R'];
                if (S[i][0] == 'C') ++cnt['C'];
                if (S[i][0] == 'H') ++cnt['H'];                
        }       
        vll freq{cnt['M'], cnt['A'], cnt['R'], cnt['C'], cnt['H']};

        ll ans = 0;
        rep(i, 0, 5) {
                rep(j, i+1, 5) {
                        rep(k, j+1, 5) {
                                ans += freq[i] * freq[j] * freq[k];
                        }
                }
        }
        cout << ans << endl;
}