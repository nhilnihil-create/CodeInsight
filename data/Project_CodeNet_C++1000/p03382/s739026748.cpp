#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define INF (1LL << 62)

#define PI (acos(-1))
#define print(x) cout << x << endl
 
ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll countDigit(ll n) { return floor(log10(n) + 1); } 
typedef pair <ll,ll> P;
static const ll dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};

template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) 
{ 
    for (int i = 0; i < (int)v.size(); ++i) os << v[i] << " ";  
    return os; 
}

template <typename T1, typename T2> 
ostream& operator<<(ostream& os, const map<T1, T2>& m) 
{ 
    for (auto p : m) os << "<" << p.first << ", " << p.second << "> "; 
    return os; 
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) { 
        cin >> a[i];
    }
    sort(all(a));
    ll ans = a[n-1];
    ll tmp = INF;
    ll r = 0;
    rep(i, n) {
        if (abs((ans+1) / 2 - a[i]) < tmp) {
            tmp = abs((ans+1) / 2 - a[i]);
            r = a[i];
        }
    }
    print(ans << " " << r);
    return 0;
}