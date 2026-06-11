#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
using namespace std;
int n,k;
int a[103];
bool dp[100005];
main() {
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int x = 1; x <= k; x++)
        for (int j = 1; a[j] <= x&&j<=n; j++)
        if (dp[x - a[j]] == 0)
                dp[x] = 1;
    if (dp[k]) cout << "First";
    else cout << "Second";
}
