#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

long long  digsum(long long  n) {
    long long  res = 0;
    while(n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}

//ミョ(-ω- ?)
int main() {
    ll n;
    cin >> n;
    ll res = INF;
    for(ll i = 1;i<n;i++){
        res = min(res,digsum(i) + digsum(n-i));
    }
    cout << res << endl;
    return 0;
}