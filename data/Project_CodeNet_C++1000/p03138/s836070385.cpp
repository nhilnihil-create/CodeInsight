#include <iostream>
using namespace std;

int n, cnt[40][2], k[40];
long long a[100005], dp[40][2], K;

long long f(int pos, bool flag){
    if (pos == -1) return 0;
    if (dp[pos][flag] != -1) return dp[pos][flag];
    int upper;
    if (flag) upper = 1;
    else if (k[pos]) upper = 1;
    else upper = 0;
    long long mx = 0;
    for (int i = 0; i <= upper; i++){
        mx = max(mx, f(pos-1, flag||i!=k[pos])+(1LL<<pos)*cnt[pos][i^1]);
    }
    return dp[pos][flag] = mx;
}

int main() {
    cin >> n >> K;
    for (int i = 0; i < 40; i++){
        if (K & (1LL << i)) k[i] = 1;
    }
    for (int i = 0; i < n; i++){
        cin >> a[i];
        for (int j = 0; j < 40; j++){
            if (a[i] & (1LL<<j)) cnt[j][1]++;
            else cnt[j][0]++;
        }
    }
    for (int i = 0; i < 40; i++){
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    cout << f(39, false) << "\n";
}
