#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define repreverse(i, start, end) for (long long i = start; i >= end; --i)
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
template<class T, class U>bool haskey(T mp, U key) { return mp.find(key) != mp.end(); }
template<class T, class U>bool isin(T el, U container) { return find(all(container), el) != container.end(); }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<class T>ld deg2rad(T deg) { return M_PI * deg / 180.0; }
template<class T>ld rad2deg(T rad) { return 180.0 * rad / M_PI; }
ll intpow(ll a,ll n){ll p=1;while(n){if(n&1)p*=a;a*=a;n>>=1;}return p;}
const long double pi = M_PI;
const long long big = 1LL << 50;
const long long inf = 1LL << 60;
const long long mod = 1e9 + 7;



int main()
{
        string S, T;
        cin >> S >> T;
        map<char, ll> mp1, mp2;
        rep(i, 0, len(S)) mp1[S[i]]++;
        rep(i, 0, len(T)) mp2[T[i]]++;

        multiset<ll> ms1, ms2;
        for (auto el : mp1) {
                ms1.insert(el.second);
        }
        for (auto el : mp2) {
                ms2.insert(el.second);
        }
        multiset<ll> res;
        set_intersection(all(ms1), all(ms2), inserter(res, res.begin()));
        if (len(res) == len(ms1)) {
                cout << "Yes" << endl;
        } else {
                cout << "No" << endl;
        }
}