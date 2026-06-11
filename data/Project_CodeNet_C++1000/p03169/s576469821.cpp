#include <bits/stdc++.h>

using namespace std;

int n;
int arr[3] = {};
double memo[301][301][301] = {};

double dp(int a, int b, int c)
{
    if (a < 0 || b < 0 || c < 0)
        return 0;
    if (a + b + c == 0)
        return 0;
    if (memo[a][b][c] > 0)
        return memo[a][b][c];
    double ex = 1;
    ex += ((double) a / n) * dp(a - 1, b, c);
    ex += ((double) b / n) * dp(a + 1, b - 1, c);
    ex += ((double) c / n) * dp(a, b + 1, c - 1);
    ex = ex / ((a + b + c) / (double) n);
    memo[a][b][c] = ex;
    return ex;
    
}

int main(void)
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int ipt;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ipt);
        arr[ipt - 1]++;
    }
    double res;
    res = dp(arr[0], arr[1], arr[2]);
    cout.precision(13);
    cout << res << endl;
    
}