#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9+7;

int dp[1001][1001];
char grid[1001][1001];

int main() {
    int r, c;
    scanf("%d%d", &r, &c);
    int up, left;


    for (int i=0; i < r; i++)
        scanf("%s", &grid[i]);
    dp[0][0] = 1;
    for (int i=0; i < r; i++) {
        for (int j=0; j < c; j++) {
            up = 0; left = 0;
            // calculate up paths
            if (i-1 >= 0 && grid[i][j] == '.')
                up = dp[i-1][j];
            else
                up = 0;
            if (j-1 >= 0 && grid[i][j] == '.')
                left = dp[i][j-1];
            else
                left = 0;
            if (i != 0 || j != 0)
                dp[i][j] = (up+left) % MOD;
        }
    }
    cout << dp[r-1][c-1] << endl;
}
