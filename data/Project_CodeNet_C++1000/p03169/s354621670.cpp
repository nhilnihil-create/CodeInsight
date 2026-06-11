//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;

int N;
double dp[305][305][305];
bool flag[305][305][305];

double rec(int i, int j, int k) {

    if (flag[i][j][k]) return dp[i][j][k];
    flag[i][j][k] = true;

    if (i == 0 && j == 0 && k == 0) return 0.0;

    double res = 0.0;

    if (i > 0) res += rec(i-1, j, k) * ((double)i / N);
    if (j > 0) res += rec(i+1, j-1, k) * ((double)j / N);
    if (k > 0) res += rec(i, j+1, k-1) * ((double)k / N);
    res += 1;
    res *= (double)N / (i+j+k);

    return dp[i][j][k] = res;
}


void solve() {
    cin >> N;
    vector<int> cnt(4);
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    cout << setprecision(15) << rec(cnt[1], cnt[2], cnt[3]) << endl;
}


int main() {
    solve();
    return 0;
}