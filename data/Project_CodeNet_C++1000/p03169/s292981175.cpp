#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double N;
double dp[305][305][305];
double dfs(int A,int B,int C) {
    if(dp[A][B][C] >= 0) {
        return dp[A][B][C];
    }
    if(A == 0 && B == 0 && C == 0) {
        return 0;
    }
    double res = 0;
    if(A) res+=dfs(A-1,B,C)*A;
    if(B) res+=dfs(A+1,B-1,C)*B;
    if(C) res+=dfs(A,B+1,C-1)*C;
    res+=N;
    res*=(1.0/(A+B+C));
    dp[A][B][C] = res;
    return res;
}
signed main(){
    cin >> N;
    vector<int>a(N);
    int cnt1 = 0,cnt2 = 0,cnt3 = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        if(a[i] == 1) cnt1++;
        if(a[i] == 2) cnt2++;
        if(a[i] == 3) cnt3++;
    }
    for(int i = 0; i < 305; i++) {
        for(int j = 0; j < 305; j++) {
            for(int k = 0; k < 305; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    cout << fixed << setprecision(20) << dfs(cnt1,cnt2,cnt3) << endl;
}
