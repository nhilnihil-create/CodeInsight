#include <bits/stdc++.h>

#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (long long)(a); i <= (long long)(n); i++)
#define irrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define irrep2(i,a,n) for(int i = (int)(n); i >= (int)(a); i--)
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

const double PI = 3.1415926535897932;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;
const ll MOD = 1000000007;
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

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
void chmin(T &a, T &b) { a = min(a, b); }

template<typename T> inline
void chmax(T &a, T &b) { a = max(a, b); }

int main(void)
{
    int n, m;
    cin >> n >> m;

    v_int a(n);
    cin >> a;

    sort(a.begin(), a.end());
    
    vector<pii> b; 
    irep(i, m) {
        int x, y;
        cin >> x >> y;
        b.push_back(pii(y,x)); 
    }

    sort(b.rbegin(), b.rend());

    v_int c(n);
    int cnt = 0;

    irep(i, m) {
        if(cnt >= n) { break; }
        irep(j, b[i].se) {
            if(cnt >= n) { break; }
            c[cnt++] = b[i].fi;
        }
    }
    
    ll sum = 0;
    irep(i, n) {
        sum += max(c[i], a[i]); 
    }
    cout << sum << endl;
    return 0;
}

/*atcoder*/
