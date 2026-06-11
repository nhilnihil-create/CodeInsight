#include <bits/stdc++.h>

using namespace std;

const int MAX_K = 123456;
int n, k, a[MAX_K];
bool dp[MAX_K];

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[a[i]] = true;
    }

    for (int i = 1; i <= k; i++)
        for (int j = 0; j < n; j++) {

            if (i - a[j] < 0)
                break;

            else {
                if (!dp[i - a[j]]) {

                    dp[i] = true;

                    break;
                }
            }
        }

    if (dp[k])
        cout << "First" << endl;
    else
        cout << "Second" << endl;
    return 0;
}