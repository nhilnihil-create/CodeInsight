#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4, MOD = 1e9 + 7;

char c[N];
int val[N][N];

signed main() {
    /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    val[0][0] = 1;
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    
    for(int i = 1; i < n; i++) {
        int i1 = i-1;
        if(c[i1] == '<') {
            for(int j = 0; j < i; j++)
                val[i][j+1] = (val[i][j] + val[i1][j]) % MOD;
        } else {
            for(int j = i-1; j > -1; j--)
                val[i][j] = (val[i1][j] + val[i][j+1]) % MOD;
        }
    }
    int t = 0;
    for(int i = 0; i < n; i++)
        t = (t + val[n-1][i]) % MOD;
    cout << t;
}