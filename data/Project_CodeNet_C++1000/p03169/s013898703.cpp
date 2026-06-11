#include <bits/stdc++.h>
using namespace std;

double sum=0;
double dp[333][333][333]={0};
bool vis[333][333][333]={false};
double dfs(int a, int b, int c) {
    if (min({a,b,c}) < 0) return 0.0;
    if (a+b+c<=0) return 0.0;
    if (vis[a][b][c]) {
        return dp[a][b][c];
    }
    double k = a+b+c;
    vis[a][b][c]=true;
    dp[a][b][c] = sum / k +
            a / k * dfs(a-1,b,c) +
            b / k * dfs(a+1, b-1, c) +
            c / k * dfs(a, b+1, c-1);
    return dp[a][b][c];
}
int main() {
    int n;cin>>n;
    int a=0,b=0,c=0;
    for (int i=0;i<n;i++) {
        int z;cin>>z;
        a += z==1;
        b += z==2;
        c += z==3;
    }
    sum = n;
    printf("%.9f\n", dfs(a, b, c));
}