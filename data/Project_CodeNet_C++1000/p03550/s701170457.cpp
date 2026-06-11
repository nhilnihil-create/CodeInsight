#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

#define MAX_N 2000

int n;
ll z,w;
ll a[MAX_N];
ll dp[MAX_N + 1][2][2][MAX_N + 1];

ll rec(int depth, bool now, bool ok, int have){
    if(dp[depth][now][ok][have] != -1) return dp[depth][now][ok][have];
    if(depth == n){
        ll X, Y;
        if(now){
            X = a[depth - 1];
            Y = a[have];
        }else{
            Y = a[depth - 1];
            X = a[have];
        }
        if(have == n) Y = w;
        return dp[depth][now][ok][have] = abs(X - Y);
    }
    ll res;
    if(now){
        res = 0;
        res = max(res, rec(depth + 1, true, true, have));
        if(ok) res = max(res, rec(depth + 1, false, false, depth));
    }else{
        res = INF;
        res = min(res, rec(depth + 1, false, true, have));
        if(ok) res = min(res, rec(depth + 1, true, false, depth));
    }
    return dp[depth][now][ok][have] = res;
}

signed main(){
    cin >> n >> z >> w;
    REP(i,n){
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0, true, false, n) << endl;
    return 0;
}