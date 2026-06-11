#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for(int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 17
#define MAX_M 1000005

ll dp[MAX_M];
ll a[MAX_N][MAX_N];
ll sum[MAX_M];
int n, m;

void dfs(int x){
    if(dp[x] != -1) return;
    dp[x] = sum[x];
    if(__builtin_popcount(x) <= 1) return;

    for(int i = x; i > 0; --i &= x){
        int y = i;
        int z = i ^ x;
        if(y == 0 || z == 0) continue;
        dfs(y);
        dfs(z);
        dp[x] = max(dp[x], dp[y]+dp[z]);
    }

    return;
}

int main() {
    cin >> n;
    rep(i,n)rep(j,n)cin >> a[i][j];

    m = 1 << n;

    rep(i,m){
        vector<int> f;
        int ii = i;
        rep(j,n){
            if(ii % 2 == 1) f.push_back(j);
            ii /= 2;
        }
        rep(j,f.size()){
            srep(k,j+1,f.size()){
                sum[i] += a[f[j]][f[k]];
            }
        }
    }

    rep(i,m)dp[i] = -1;

    dfs(m-1);

    ll ans = dp[m-1];

    cout << ans << endl;
    return 0;
}


