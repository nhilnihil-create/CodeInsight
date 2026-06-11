#include<bits/stdc++.h> 
#define ll long long
#define pb push_back
#define ld double
using namespace std;

ld dp[312][312][312];


int main(){
 
    int n;
    cin >> n;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            c1++;
        } else if (x == 2) {
            c2++;
        } else {
            c3++;
        }
    }
 
    for (int k = 0; k < 307; k++) {
        for (int j = 0; j + k < 307; j++) {
            for (int i = 0; i + j + k < 307; i++) {
                if (i == 0 && j == 0 && k == 0) {
                    continue;
                }
                if (i + j + k > 307) {
                    continue;
                }
                ld wait = 1.0 * n / (i + j + k);
                ld pi = 1.0 * i / (i + j + k);
                ld pj = 1.0 * j / (i + j + k);
                ld pk = 1.0 * k / (i + j + k);
 
                if (i) {
                    dp[i][j][k] += pi * dp[i - 1][j][k];
                }
                if (j) {
                    dp[i][j][k] += pj * dp[i + 1][j - 1][k];
                }
                if (k) {
                    dp[i][j][k] += pk * dp[i][j + 1][k - 1];
                }
                dp[i][j][k] += wait;
            }
        }
    }
 
    cout.precision(10);
    cout << fixed << dp[c1][c2][c3] << "\n";
  
return 0;
}