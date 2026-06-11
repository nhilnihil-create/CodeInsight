#include<bits/stdc++.h>
#define int long long
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
using namespace std;
const int mod = 1e9+7;
const int N = 2e5+5;
string s[3005];
int ans[3005][3005];
main() {
    ios::sync_with_stdio(0);
    int r,c;
    cin >> r >> c;
    ans[0][0] = 1;
    for (int i = 0;i < r; i++)
        cin >> s[i];
    for (int i = 0; i < r; i++)
    for (int j = (i == 0 ? 1 : 0); j < c; j++) {
            if (s[i][j] == '.') {
            if (i)
        ans[i][j] = ans[i-1][j];
        if (j) ans[i][j] += ans[i][j-1];
        if (ans[i][j] > mod) ans[i][j] -= mod;
    }}
    cout << ans[r-1][c-1];



}

