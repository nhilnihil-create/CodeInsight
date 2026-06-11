#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e7 + 10;

int n, T, k, m;

int a[MAXN], dp[MAXN];

string s, t;

const int MOD = 1e9 + 7;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 1; i <= k; i++) {
        bool isPos = 0;
        for (int j = 0; j < n; j++)
            if (i - a[j] >= 0 && !dp[i - a[j]])
                isPos = 1;
        
        dp[i] = isPos;
    }

    if (dp[k] == 1)
        cout << "First";
    else
        cout << "Second";
}
