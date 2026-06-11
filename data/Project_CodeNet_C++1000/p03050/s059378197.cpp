#include <bits/stdc++.h>

#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define irrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define irrep2(i,n,a) for(int i = (int)(n); i >= (int)(a); i--)
#define fi first
#define se second

using ll = long long;
using v_int = std::vector<int>;
using v2_int = std::vector<v_int>;
using v_ll = std::vector<ll>;
using v2_ll = std::vector<v_ll>;
using v_string = std::vector<std::string>;
using v_bool = std::vector<bool>;
using v2_bool = std::vector<v_bool>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using mii = std::map<int, int>;
using mll = std::map<ll, ll>;

const double PI = 3.1415926535897932;
const int INF = 2*(int)1e9;
const ll LINF = (ll)1e18;
const ll MOD = 1000000007;
//const int dc[4] = {1, -1, 0,  0};
//const int dr[4] = {0,  0, 1, -1};
const int dc[8] = {1, -1, 0,  0, 1, -1,  1, -1};
const int dr[8] = {0,  0, 1, -1, 1,  1, -1, -1};

using namespace std; 

template<typename T, typename U> inline
ostream& operator<<(ostream &o, pair<T,U> &p)
{
    return o << "{" << p.first << "," << p.second << "}";
}

template<typename T, typename U, typename V> inline
ostream& operator<<(ostream &o, tuple<T,U,V> &p)
{
    return o << "{" << get<0>(p) << "," << get<1>(p) << "," << get<2>(p) << "}";
}

template<typename T> inline
istream& operator>>(istream &is, vector<T> &v)
{
    int len = (int)v.size();
    for(int i = 0; i < len; i++) {
        is >> v[i]; 
    }
    return is;
}

template<typename T> inline
ostream& operator<<(ostream &os, vector<T> &v)
{
    int len = (int)v.size();
    for(int i = 0; i < len; i++) { 
        os << v[i];
        if(i != len-1) { os << ","; } 
    } 
    return os;
}

template<typename T> inline
void chmin(T &a, T b) { a = min(a, b); }

template<typename T> inline
void chmax(T &a, T b) { a = max(a, b); }

ll solve(ll n, ll m)
{
    if(m==0) { return 0; }

    if(n%m == n/m) {
        return m;
    } else {
        return 0;
    }
}

ll getSum(ll n) 
{
    ll ans = 0;

    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ans += solve(n, i-1);     
            if(i * i != n) ans += solve(n, n/i-1);
        }
    }
    return ans;
}

int main(void)
{
    ll n;
    cin >> n;
    
    cout << getSum(n) << endl;
    return 0;
}

/*atcoder*/
