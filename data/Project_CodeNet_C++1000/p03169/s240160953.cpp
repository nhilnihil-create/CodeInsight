#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define f first
#define s second
#define int long long
#define pb push_back
#define pencho ios_base::sync_with_stdio(false);cin.tie(NULL);
#define N 305
#define mod 1000000007

double dp[N][N][N];
int n;

double solveDp(int cnt_1, int cnt_2, int cnt_3) {

       if (cnt_1 < 0 || cnt_2 < 0 || cnt_3 < 0)      return 0;
       if ((int)dp[cnt_1][cnt_2][cnt_3] != -1)    return dp[cnt_1][cnt_2][cnt_3];

       dp[cnt_1][cnt_2][cnt_3] = ((1.0) * n) / (cnt_1 + cnt_2 + cnt_3)
                                 + (((1.0) * cnt_1) * (solveDp(cnt_1 - 1, cnt_2, cnt_3))) / (cnt_1 + cnt_2 + cnt_3)
                                 + (((1.0) * cnt_2) * (solveDp(cnt_1 + 1, cnt_2 - 1, cnt_3))) / (cnt_1 + cnt_2 + cnt_3)
                                 + (((1.0) * cnt_3) * (solveDp(cnt_1, cnt_2 + 1, cnt_3 - 1))) / (cnt_1 + cnt_2 + cnt_3);
       return dp[cnt_1][cnt_2][cnt_3];
}


void solve() {
       pencho
       cin >> n;
       int cnt_1 = 0, cnt_2 = 0, cnt_3 = 0, cnt;

       for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) for (int k = 0; k < N; k++) dp[i][j][k] = -1;

       for (int i = 1; i <= n; i++) {
              cin >> cnt;
              if (cnt == 1)    cnt_1++;      else if (cnt == 2)      cnt_2++;      else cnt_3++;
       }
       dp[0][0][0] = 0;
       solveDp(cnt_1, cnt_2, cnt_3);
       cout << fixed << setprecision(10) << dp[cnt_1][cnt_2][cnt_3];
}


signed main()
{
#ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("o.txt", "w", stdout);
#endif

       solve();
}