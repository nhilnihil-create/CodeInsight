#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef pair<int, int> ii;
typedef long long ll;

const int len = 2e4+5, mx = 1e4;
ll dp[len];
pair<ii, int> arr[len];

bool comp(pair<ii, int> a, pair<ii, int> b){
    return (a.fi.fi+a.fi.se > b.fi.fi+b.fi.se);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d %d", &arr[i].fi.fi, &arr[i].fi.se, &arr[i].se);
    sort(arr+1, arr+1+n, comp);

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= mx; j++)
            if (j <= arr[i].fi.se)
                dp[j] = max(dp[j], dp[j+arr[i].fi.fi]+arr[i].se);

    printf("%lld\n", dp[0]);
    return 0;
}
