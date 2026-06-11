#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;
const int N = 5001;
int n, A, B;
int a[N];
long long f[N][N + 1];
int main(){
    scanf("%d %d %d", &n, &A, &B);
    for (int i = 1; i <= n ;  i ++) {
        int x;
        scanf("%d", &x);
        a[x] = i;
    }
    for (int i = 1; i <= n ; i ++)
        for (int j  = 0; j <= n + 1; j ++)
            f[i][j] = 1e18;
    for (int i = 0; i < n ; i ++) {
        for (int j = 0; j <= n ; j ++)
            f[i][j + 1] = min(f[i][j + 1], f[i][j]);
        for (int j = 0; j <= n + 1; j++) {
            if (j == a[i + 1])
                f[i + 1][j]= min(f[i][j], f[i + 1][j]);
            else
                if (a[i + 1] > j)
                    f[i + 1][j]= min(f[i][j] + B, f[i + 1][j]);
                else    f[i + 1][j]= min(f[i][j] + A, f[i + 1][j]);

        }
    }
    long long ans =1e18;
    for (int i = 0; i <= n + 1; i ++)
        ans = min(ans, f[n][i]);
    printf("%lld\n", ans);
    return 0;
}