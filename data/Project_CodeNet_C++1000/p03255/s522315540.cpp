#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;

const int len = 2e5+5;
const ll inf = 1e18;
int arr[len], n, x;
ll dp[len];

ll solve(int i){
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];

    ll ans = inf, sum = 2*arr[i] + x, cur = 3;
    for (int j = i; j >= 1; j--){
        sum += arr[j]*1LL*cur;
        cur += 2;
        ans = min(ans, sum + solve(j-1));
    }

    //printf("i = %d, ans = %lld\n", i, ans);
    return dp[i] = ans;
}

ll check(int k){
    //printf("k = %d\n", k);
    ll ans = (n+k)*1LL*x;
    int cur = 3, pos = n;
    while (pos > 0){
        //printf("pos = %d\n", pos);
        for (int temp = 0; temp < k && pos > 0; temp++){
            if (cur == 3)
                ans += 5*1LL*arr[pos];
            else
                ans += cur*1LL*arr[pos];

            pos--;
        }

        cur+=2;
    }

    return ans;
}

int main(){
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    //for (int i = 1; i <= n; i++)
      //  dp[i] = -1;

    int l = 0, r = n;
    while (l+1 < r){
        int mid = (l+r)/2;
        if (check(mid) < check(mid+1))
            r = mid;
        else
            l = mid;
    }

    printf("%lld\n", check(l+1));
    return 0;
}
