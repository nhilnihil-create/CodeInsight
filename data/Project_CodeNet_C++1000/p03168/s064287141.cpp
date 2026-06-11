#include<bits/stdc++.h>
//#define int long long
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
double ans[3005][3005];
double p[3005];
main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    ans[0][0] = 1;
    for (int i = 1; i <= n; i++)
    for (int j = 0; j <= n; j++) {
            if (j)
        ans[i][j] = ans[i-1][j-1]*p[i];
        ans[i][j] += ans[i-1][j]*(1-p[i]);
    }
    double x = 0;
    for (int i = n/2 + 1;i <= n; i++)
        x += ans[n][i];
    cout << fixed << setprecision(10) << x;


}

