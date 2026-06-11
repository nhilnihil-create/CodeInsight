#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, k;
    cin >> n >> k;    
    vector<int> a(n);
    bool dp[k + 1];
    memset(dp, false, sizeof dp);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i + a[j] <= k) {
                dp[i + a[j]] |= !dp[i];
            }
        }
    }
    if (dp[k])
        cout << "First" << endl;
    else
        cout << "Second" << endl;

	return 0;
}