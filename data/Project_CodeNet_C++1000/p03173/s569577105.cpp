# include <bits/stdc++.h>
using namespace std;
# define lli long long int
# define INF 100000000000000

lli sum[401][401];
lli dp[401][401];


lli findMin(lli i, lli j){
    if(i == j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    lli minVal = INF;
    for(lli k = i; k < j; k++){
        minVal = min(minVal, sum[i][j] + findMin(i, k) + findMin(k + 1, j));
    }

    return dp[i][j] = minVal;

}


void solve(){
    lli n;
    cin >> n;

    lli arr[n];
    for(lli i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(lli i = 0; i < n; i++){
        for(lli j = i; j < n; j++){
            if(i == j)
                sum[i][j] = arr[j];
            else
                sum[i][j] = arr[j] + sum[i][j - 1];
        }
    }

    cout << findMin(0, n - 1);

}


int main(){

    memset(dp, -1, sizeof(dp));
    solve();

}
