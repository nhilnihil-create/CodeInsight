#include <bits/stdc++.h>

#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (long long)(a); i <= (long long)(n); i++)
#define irrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define irrep2(i,a,n) for(int i = (int)(n); i >= (int)(a); i--)

typedef long long ll;
typedef std::vector<int> v_int;
typedef std::vector<v_int > v2_int;
typedef std::vector<ll> v_ll;
typedef std::vector<v_ll > v2_ll;
typedef std::vector<std::string> v_string;
typedef std::vector<v_string > v2_string;
typedef std::vector<bool> v_bool;
typedef std::vector<v_bool > v2_bool;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

const double PI = 3.14159265359;
const int INF = (int)1e9;
const ll LINF = 1e18;
const int IMOD = 1000000007;
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

using namespace std; 

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a; }
ll lcm(ll a, ll b) { return a*(b/gcd(a,b)); }

int main(void)
{
    int n, m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    
    ll l = lcm(n,m); 
    ll g = gcd(n,m);

    ll a = n/g;
    ll b = m/g;
    bool ok = true;
    irep(i, g) {
        if(s[a*i] != t[b*i]) {
            ok = false;
        }
    }
    if(ok) {
        cout << l << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
/** atcoder **/

