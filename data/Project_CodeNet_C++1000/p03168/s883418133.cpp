#include <bits/stdc++.h>
using namespace std;
#define N 3050
int n;
const double EPS = 1e-10;
double memo[N][N],p[N];

bool equal(double a , double b) {
    return fabs(a - b) <= EPS;
}

double dp(int curr , int head) {
    if (curr > n) return head > (n / 2) ? 1 : 0;
    double &sol = memo[curr][head];
    if (!equal(sol , -1)) return sol;
    return sol =
        dp(curr + 1 , head + 1) * p[curr] +
        dp(curr + 1 , head) * (1 - p[curr]);
}

int main() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; i++)
        scanf("%lf" , &p[i]);
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < N ; j++)
            memo[i][j] = -1;
    printf("%.10lf\n" , dp(1 , 0));
}
