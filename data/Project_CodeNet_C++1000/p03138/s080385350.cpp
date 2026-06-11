#pragma region header
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rev(i, n) for(int i = (int)(n - 1); i >= 0; i--)
#define rev1(i, n) for(int i = (int)(n); i > 0; i--)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define resort(v) sort((v).rbegin(), (v).rend())
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
using ll = long long;
using P = pair<int, int>;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
constexpr ll mod = 1e9+7;
constexpr ll inf = INT32_MAX/2;
constexpr ll INF = LLONG_MAX/2;
constexpr long double eps = DBL_EPSILON;
constexpr long double pi = 3.141592653589793238462643383279;



template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

ll fact(int i) {       
    if (i == 0) return 1;
    return (fact(i - 1)) * i % mod;
}
ll gcd(ll a, ll b) {        
    if(b == 0) return a;
    return gcd(b, a % b); 
}
ll lcm(ll a, ll b) {      
    return a / gcd(a, b) * b ;
}
int keta(ll n) {       
    if(n == 0) return 1;
    int count = 0;
    while(n != 0) {
        n /= 10;
        count++;
    }
    return count;
}
ll ketasum(ll n) {   
    ll sum = 0;
    while(n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

#pragma endregion
int v[40];
int ans[40];
signed main() {
    int n,k;cin >> n >> k;
    vi vec(n);
    rep(i, n) {
        int a;cin >> a;
        vec[i]=a;
        int j = 0;
        while(a>0) {
            if(a&1) v[j]++;
            // cout << a << ' ' << j << endl;
            j++;
            a>>=1;
            // cout << a << ' ' << j << endl;
        }
    }
    rep(i, 40) {
        if(v[i]<=n/2) ans[i]=1;
    }
    int x = 0;
    rev(i, 40) {
        if(x+ans[i]*pow(2,i)>k) {
            // cout << i << endl;
            // break;
            continue;
        }
        x+=ans[i]*pow(2,i);
    }
    int sum = 0;
    // x=0;
    // for(;x<=k;x++) {
        // sum=0;
        rep(i, n) sum+=vec[i]^x;
        // cout << x << ":" << sum << endl;
    // }
    cout << sum << endl;
    // cout << x << endl;
    // rep(i, 5) cout << v[i] << ' ';cout << endl;
    return 0;
}