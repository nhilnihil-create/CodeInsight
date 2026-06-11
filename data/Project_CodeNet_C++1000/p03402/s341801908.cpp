#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }
template<typename T> inline T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }






int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    
    // 解説みた
    
    int a, b;
    cin >> a >> b;
    
    const int maxn = 100; // 10でdebug
    char x = '.', y = '#';
    
    char table[maxn][maxn];
    rep(i, maxn) {
        rep(j, maxn / 2) table[i][j] = y;
        rep3(j, maxn / 2, maxn) table[i][j] = x;
    }
    int c = 0, c2 = 0;
    for (int i = 0; i < maxn; i += 2) {
        for (int j = 0; j < maxn / 2 - 1; j += 2) {
            c++;
            if (c > a - 1) break;
            table[i][j] = x;
        }
        
        for (int j = maxn / 2 + 1; j < maxn; j += 2) {
            c2++;
            if (c2 > b - 1) break;
            table[i][j] = y;
            
        }
    }
    
    
    
    cout << maxn << " " << maxn << endl;
    rep(i, maxn) { rep(j, maxn) cout << table[i][j]; cout << endl; } // 空白入れててwa
}




