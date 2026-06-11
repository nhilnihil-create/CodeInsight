#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int n;
    cin >> n;
    vector<vector<int> > a(2, vector<int>(n));
    for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    for (int i = 0; i < n - 1; i++) {
        a[0][i+1] += a[0][i];
        a[1][n-2-i] += a[1][n-1-i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, a[0][i] + a[1][i]);
    cout << ans << '\n';
}
