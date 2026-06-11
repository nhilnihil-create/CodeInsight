#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>; 
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
    int a = x2 - x1, b = y2 - y1;
    int x3, x4, y3, y4;
    x3 = x2 - b, y3 = y2 + a,
    x4 = x3 - a, y4 = y3 - b;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << ln;
}
    

