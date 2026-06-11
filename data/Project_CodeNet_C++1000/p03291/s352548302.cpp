#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int add(int i, int j) {
    if((i += j) >= mod) i -= mod;
    return i;
}

int mult(int i, int j) {
    return (ll) i * j % mod;
}

int n;
int dp[4][100000];
string line;

int f(int i, int j) {
    if(i == 4) return 0;
    if(j == n) return i == 3;
    if(dp[i][j] > -1) return dp[i][j];
    if(line[j] == '?') return dp[i][j] = add(f(i + 1, j + 1), mult(3, f(i, j + 1)));
    int mx = f(i, j + 1);
    if(i == line[j] - 'A') mx = add(mx, f(i + 1, j + 1));
    return dp[i][j] = mx;
}

int main() {
    cin >> line;
    n = line.size();
    memset(dp, -1, sizeof dp);
    cout << f(0, 0);
    
    return 0;
}