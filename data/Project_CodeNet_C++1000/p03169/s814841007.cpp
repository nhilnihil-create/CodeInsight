#include<bits/stdc++.h>
using namespace std;

const int MAXN = 310;
int N;
int a[MAXN];
double dp[MAXN][MAXN][MAXN];

int cnt[4];

double solve(int x, int y, int z) {
    double ret;
    if(x==0 && y==0 && z==0) return 0;
    if(dp[x][y][z]>0.0) return dp[x][y][z];
    int sum = x+y+z;
    ret = 1.0*N/sum;
    if(x>0) {
        ret += 1.0*x/sum * solve(x-1, y, z);
    }
    if(y>0) {
        ret += 1.0*y/sum * solve(x+1, y-1, z);
    }
    if(z>0) {
        ret += 1.0*z/sum * solve(x, y+1, z-1);
    }
    return dp[x][y][z] = ret;
}
int main() {
    cin >> N;
    memset(cnt, 0, sizeof(cnt));
    for(int i=1; i<=N; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    cout <<fixed<<setprecision(14) <<solve(cnt[1], cnt[2], cnt[3]) << endl;
    return 0;
}