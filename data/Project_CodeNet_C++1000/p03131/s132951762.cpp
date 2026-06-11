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
//ミョ(-ω- ?)
int main() {
    ll k,a,b;
    cin >> k >> a >> b;
    if(b - a <= 2)cout << k + 1 << endl;
    else{
        ll x = max(0LL,(k - a + 1)/2);
        if(x == 0)cout << k + 1 << endl;
        else cout << (x - 1) * (b - a) + b + (k - a + 1)%2 << endl;
    }
    return 0;
}