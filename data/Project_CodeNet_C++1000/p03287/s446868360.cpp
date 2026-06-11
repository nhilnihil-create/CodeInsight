#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define repreverse(i, start, end) for (long long i = start; i >= end; --i)
#define all(x) (x).begin(), (x).end()
#define len(x) ((long long)(x).size())
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vllvll = vector<vll>;
using pll = pair<ll, ll>;
template<class T>void print1d(T x,ll n=-1){if(n==-1)n=x.size();rep(i,0,n){cout<<x[i]<<' ';}cout<<'\n';}
template<class T>void print2d(T x,ll r=-1,ll c=-1){if(r==-1)r=x.size();if(c==-1)c=x[0].size();rep(i,0,r)print1d(x[i],c);}
template<class T, class U>bool haskey(T mp, U key) { return mp.find(key) != mp.end(); }
template<class T, class U>bool isin(T el, U container) { return find(all(container), el) != container.end(); }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<class T>bool even(T n) { return ! (n & 1); }
template<class T>bool odd(T n) { return n & 1; }
template<class T>ld deg2rad(T deg) { return M_PI * deg / 180.0; }
template<class T>ld rad2deg(T rad) { return 180.0 * rad / M_PI; }
ll intpow(ll a,ll n){ll p=1;while(n){if(n&1)p*=a;a*=a;n>>=1;}return p;}
const long double pi = M_PI;
const long long big = 1LL << 50;
const long long inf = 1LL << 60;
const long long mod = 1e9 + 7;

ll com(ll n)
{
        return n * (n-1) / 2;
}

int main()
{
        ll N, M;
        cin >> N >> M;
        vll A(N);
        rep(i, 0, N) cin >> A[i];

        vll acc(N+1);
        rep(i, 1, N+1) acc[i] += acc[i-1] + A[i-1];


/*
        ll right = 0;
        ll sm = 0;
        ll ans = 0;
        rep(left, 0, N) {
                while (right < N and (acc[right+1] - acc[left]) % M == 0) {
                        sm += A[right];
                        ++right;
                }
                cout << "left, right: " << left << ' ' << right << endl;
                ans += right - left;

                if (left == right) ++right;
                else sm -= A[left];

        }
*/
/*
        acc.erase(acc.begin());

        vector<bool> is(N);
        rep(i, 0, N) {
                if (acc[i] % M == 0) {
                        is[i] = 1;
                }
        }

        print1d(is);

        ll ans = 0;
        ll cnt = 0;

        rep(i, 0, N) {
                if (i == 0) {
                        if (is[i]) ++ans;
                        ++cnt;
                } else {        
                        if (is[i]) {
                                ans += (cnt+1) * cnt;
                                ++cnt;
                        }
                }
        }
        cout << ans << endl;
*/
        unordered_map<ll, ll> rems;
        rep(i, 0, N+1) {
                rems[acc[i] % M]++;
        }
        ll ans = 0;
        for (auto x : rems) {
                ans += com(x.second);
        }

        cout << ans << endl;
}