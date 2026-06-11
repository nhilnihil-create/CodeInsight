#include <bits/stdc++.h>
using namespace std;

int n,k,x;
vector <int> V;
int dp[100010];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x;
        V.push_back(x);
    }

    for (int i = 0; i <= k; i++) {
        bool t=false;
        for (int j = 0; j < n; j++) {
            if (i - V[j] < 0) continue;
            if (dp[i - V[j]] == 0) t=true;
        }
        dp[i] = t;
    }

    if (dp[k]) cout << "First";
    else cout << "Second";
}
