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

signed main() {
    string s,t;cin >> s >> t;
    vvi v(26);
    rep(i, t.size()) v[t[i]-'a'].pb(i);
    for(auto p:v) {
        if(p.size()>1) {
            char c = s[p[0]];
            for(auto q:p) {
                if(s[q]!=c) {
                    printf("No\n");
                    return 0;
                }
            }
        }
    }
    vvi vec(26);
    rep(i, s.size()) vec[s[i]-'a'].pb(i);
    for(auto p:vec) {
        if(p.size()>1) {
            char c = t[p[0]];
            for(auto q:p) {
                if(t[q]!=c) {
                    printf("No\n");
                    return 0;
                }
            }
        }
    }
    printf("Yes\n");
    return 0;
}