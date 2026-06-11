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



int main()
{
        ll N, M;
        cin >> N >> M;

        vll x(N), y(N), z(N);
        vllvll cands;
        vector<tuple<ll, ll, ll, ll>> data(N);
        ll ans = -inf;
        rep(i, 0, N) {
                ll a, b, c;
                cin >> a >> b >> c;
                x[i] = a;
                y[i] = b;
                z[i] = c;
                data[i] = make_tuple(a, b, c, i);
        }

                if (M == 0) {
                cout << 0 << endl;
                return 0;
        }

        sort(data.rbegin(), data.rend(), [](auto a, auto b) { 
                ll p = get<0>(a);
                ll q = get<1>(a);
                ll r = get<2>(a);
                ll pp = get<0>(b);
                ll qq = get<1>(b);
                ll rr = get<2>(b);
                return p + q + r < pp + qq + rr;
        } );
        ll xtmp, ytmp, ztmp;
        xtmp = ytmp = ztmp = 0;
        ll sm;
        sm = 0;
        rep(i, 0, M) {
                xtmp += get<0>(data[i]);
                ytmp += get<1>(data[i]);
                ztmp += get<2>(data[i]);
        }
        sm = abs(xtmp) + abs(ytmp) + abs(ztmp);
        chmax(ans, sm);



        sort(data.rbegin(), data.rend(), [](auto a, auto b) { 
                ll p = get<0>(a);
                ll q = get<1>(a);
                ll r = get<2>(a);
                ll pp = get<0>(b);
                ll qq = get<1>(b);
                ll rr = get<2>(b);
                return p + q - r < pp + qq - rr;
        } );
        xtmp = ytmp = ztmp = 0;
        sm = 0;
        rep(i, 0, M) {
                xtmp += get<0>(data[i]);
                ytmp += get<1>(data[i]);
                ztmp += get<2>(data[i]);
        }
        sm = abs(xtmp) + abs(ytmp) + abs(ztmp);
        chmax(ans, sm);




        sort(data.rbegin(), data.rend(), [](auto a, auto b) { 
                ll p = get<0>(a);
                ll q = get<1>(a);
                ll r = get<2>(a);
                ll pp = get<0>(b);
                ll qq = get<1>(b);
                ll rr = get<2>(b);
                return p - q + r < pp - qq + rr;
        } );
        xtmp = ytmp = ztmp = 0;
        sm = 0;
        rep(i, 0, M) {
                xtmp += get<0>(data[i]);
                ytmp += get<1>(data[i]);
                ztmp += get<2>(data[i]);
        }
        sm = abs(xtmp) + abs(ytmp) + abs(ztmp);
        chmax(ans, sm);



        sort(data.rbegin(), data.rend(), [](auto a, auto b) { 
                ll p = get<0>(a);
                ll q = get<1>(a);
                ll r = get<2>(a);
                ll pp = get<0>(b);
                ll qq = get<1>(b);
                ll rr = get<2>(b);
                return p - q - r < pp - qq - rr;
        } );
        xtmp = ytmp = ztmp = 0;
        sm = 0;
        rep(i, 0, M) {
                xtmp += get<0>(data[i]);
                ytmp += get<1>(data[i]);
                ztmp += get<2>(data[i]);
        }
        sm = abs(xtmp) + abs(ytmp) + abs(ztmp);
        chmax(ans, sm);



        sort(data.rbegin(), data.rend(), [](auto a, auto b) { 
                ll p = get<0>(a);
                ll q = get<1>(a);
                ll r = get<2>(a);
                ll pp = get<0>(b);
                ll qq = get<1>(b);
                ll rr = get<2>(b);
                return -p + q + r < -pp + qq + rr;
        } );
        xtmp = ytmp = ztmp = 0;
        sm = 0;
        rep(i, 0, M) {
                xtmp += get<0>(data[i]);
                ytmp += get<1>(data[i]);
                ztmp += get<2>(data[i]);
        }
        sm = abs(xtmp) + abs(ytmp) + abs(ztmp);
        chmax(ans, sm);




        sort(data.rbegin(), data.rend(), [](auto a, auto b) { 
                ll p = get<0>(a);
                ll q = get<1>(a);
                ll r = get<2>(a);
                ll pp = get<0>(b);
                ll qq = get<1>(b);
                ll rr = get<2>(b);
                return -p + q - r < -pp + qq -rr;
        } );
        xtmp = ytmp = ztmp = 0;
        sm = 0;
        rep(i, 0, M) {
                xtmp += get<0>(data[i]);
                ytmp += get<1>(data[i]);
                ztmp += get<2>(data[i]);
        }
        sm = abs(xtmp) + abs(ytmp) + abs(ztmp);
        chmax(ans, sm);




        sort(data.rbegin(), data.rend(), [](auto a, auto b) { 
                ll p = get<0>(a);
                ll q = get<1>(a);
                ll r = get<2>(a);
                ll pp = get<0>(b);
                ll qq = get<1>(b);
                ll rr = get<2>(b);
                return -p - q + r < -pp - qq +rr;
        } );
        xtmp = ytmp = ztmp = 0;
        sm = 0;
        rep(i, 0, M) {
                xtmp += get<0>(data[i]);
                ytmp += get<1>(data[i]);
                ztmp += get<2>(data[i]);
        }
        sm = abs(xtmp) + abs(ytmp) + abs(ztmp);
        chmax(ans, sm);




        sort(data.rbegin(), data.rend(), [](auto a, auto b) { 
                ll p = get<0>(a);
                ll q = get<1>(a);
                ll r = get<2>(a);
                ll pp = get<0>(b);
                ll qq = get<1>(b);
                ll rr = get<2>(b);
                return -p - q - r < -pp - qq -rr;
        } );
        xtmp = ytmp = ztmp = 0;
        sm = 0;
        rep(i, 0, M) {
                xtmp += get<0>(data[i]);
                ytmp += get<1>(data[i]);
                ztmp += get<2>(data[i]);
        }
        sm = abs(xtmp) + abs(ytmp) + abs(ztmp);
        chmax(ans, sm);
        

        
        cout << ans << endl;
}