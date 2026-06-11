#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[301];
int left[301][26];
int right[301][26];
int dp[301][301][301];

int calc(int x, int y, int z) {
    int ans = 0, i;
    
    if (dp[x][y][z] >= 0) return dp[x][y][z];
    
    if (x > y) return dp[x][y][z] = 0;
    if (x == y) return dp[x][y][z] = 1;
    
    if (s[x] == s[y]) return dp[x][y][z] = calc(x + 1, y - 1, z) + 2;
    
    ans = calc(x + 1, y - 1, z);
    if (z > 0) ans = max(ans, calc(x + 1, y - 1, z - 1) + 2);
    
    if (left[y][s[x] - 'a'] > x) ans = max(ans, calc(x + 1, left[y][s[x] - 'a'] - 1, z) + 2);
    if (left[y][s[x] - 'a'] == x) ans = max(ans, 1);
    if (right[x][s[y] - 'a'] < y) ans = max(ans, calc(right[x][s[y] - 'a'] + 1, y - 1, z) + 2);
    if (right[x][s[y] - 'a'] == y) ans = max(ans, 1);
    
    return dp[x][y][z] = ans;
}

int main() {
    int n, k, i, j, l;
    
    scanf("%s", s);
    scanf("%d", &k);
    
    n = strlen(s);
    
    for (i = 0; i < 26; i++) left[0][i] = -1;
    for (i = 0; i < n; i++) {
        if (i > 0) {
            for (j = 0; j < 26; j++) left[i][j] = left[i - 1][j];
        }
        
        left[i][s[i] - 'a'] = i;
    }
    
    for (i = 0; i < 26; i++) right[n][i] = 1e9;
    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < 26; j++) right[i][j] = right[i + 1][j];
        
        right[i][s[i] - 'a'] = i;
    }
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            for (l = 0; l <= k; l++) {
                dp[i][j][l] = -1;
            }
        }
    }
    
    printf("%d\n", calc(0, n - 1, k));
    
    return 0;
}
