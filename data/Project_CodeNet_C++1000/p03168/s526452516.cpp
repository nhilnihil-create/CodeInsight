#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
#define ll long long

const int mod = 1e9+7, maxn = 1e5+10;
int N, M, K;
double p[3030], dp[3030][2];

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%lf", &p[i]);
    dp[0][0] = dp[0][1] = 1;
    int x = 0;
    for(int i = 1; i <= N; i++) {
        x ^= 1;
        for(int j = i; j > 0; j--)
            dp[j][x] = dp[j-1][x^1]*p[i] + dp[j][x^1]*(1-p[i]);
        dp[0][x] = dp[0][x^1]*(1-p[i]);
    }
//    x ^= 1;
    double sum = 0;
    for(int i = N; i > -1 && i*2 > N; i--)
        sum += dp[i][x];
    printf("%.10lf\n", sum);
    return 0;
}
