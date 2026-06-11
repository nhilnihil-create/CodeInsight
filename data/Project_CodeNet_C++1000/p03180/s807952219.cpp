#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n;

typedef long long LL;

LL a[20][20];

const int maxn = (1 << 16) + 5;
LL sum[maxn];
LL dp[maxn];

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            scanf("%lld", &a[i][j]);
        }
    }
    for(int i = 0;i < (1 << n);i++){
        for(int j = 0;j < n;j++){
            for(int k = j + 1;k < n;k++){
                if(a[j][k] == 0)
                    continue;
                if(i & (1 << j)){
                    if(i & (1 << k)){
                        sum[i] += a[j][k];
                    }
                }
            }
        }
    }
    for(int S = 1;S < (1 << n);S++){
        dp[S] = sum[S];
        for(int i = S;i > 0; i = (i - 1) & S){
            dp[S] = max(dp[S], dp[i] + dp[S ^ i]); 
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}
