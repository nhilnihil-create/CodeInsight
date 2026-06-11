#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1e18 + 10;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int ketawa(int n){
    int res = 0;
    while(n>0){
        res += n%10;
        n/=10;
    }
    return res;
}

int main(){ 
    int n, a, b; cin >> n >> a >> b;
    int res = 0;
    rept(i, 1, n+1){
        int sum = ketawa(i);
        if(sum >= a && sum <= b)res += i;
    }
    cout << res << ln;
}