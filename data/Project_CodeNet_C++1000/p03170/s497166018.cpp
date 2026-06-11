#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main() {
    //freopen("input1.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> vec(n);

    for (int i=0; i<n; i++)
        cin >> vec[i];

    vector<bool> dp(k+1, false);

    for (int i=1; i<=k; i++){
        for (int j=0; j<n; j++){
            if (i-vec[j]<=k && i-vec[j]>=0 && dp[i-vec[j]]==false)
                dp[i] = true;
        }
    }

    if (dp[k])
        cout << "First";
    else
        cout << "Second";

    return 0;
}