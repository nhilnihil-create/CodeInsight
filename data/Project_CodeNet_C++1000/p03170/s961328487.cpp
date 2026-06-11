// Created by js0805
#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<string>
#define ll long long
#define fr(a,b) for(ll i=a;i<b;i++)
#define prDouble(x) cout << fixed << setprecision(10) <<x
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
string solve(int a[], int n, int k) {
    bool dp[k + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j] > i) {
                continue;
            }
            if (dp[i - a[j]] == 0) {
                dp[i] = 1;
            }
        }
    }
    return dp[k] ? "First" : "Second";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, k;
    cin >> t >> k;
    int a[t];
    fr(0, t) cin >> a[i];
    cout << solve(a, t, k);
    return 0;
}