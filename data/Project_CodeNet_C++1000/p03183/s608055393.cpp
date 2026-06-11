#include <bits/stdc++.h>
// X - Tower

#define fi first
#define se second

using namespace std;

pair<int,pair<int,int>> arr[1005];
long long dp[1005][20005];

bool cmp(pair<int,pair<int,int>> p1,pair<int,pair<int,int>> p2) {
    return p1.fi + p1.se.fi < p2.fi + p2.se.fi;
}

int main() {
    int N,i,j;
    long long ans;

    scanf("%d",&N);

    for (i = 1;i <= N;i++)
        scanf("%d%d%d",&arr[i].se.fi,&arr[i].fi,&arr[i].se.se);

    sort(arr + 1,arr + N + 1,cmp);

    for (i = 1;i <= N;i++) {
        for (j = 0;j < arr[i].se.fi;j++)
            dp[i][j] = dp[i - 1][j];

        for (j = arr[i].se.fi;j <= arr[i].se.fi + arr[i].fi;j++)
            dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - arr[i].se.fi] + arr[i].se.se);
    }

    ans = 0;
    for (i = 0;i <= 20000;i++)
        ans = max(ans,dp[N][i]);

    printf("%lld\n",ans);

    return 0;
}
