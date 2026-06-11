#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S, T;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

vector<mat> dp(300, mat(300, vec(301, -1)));
ll dfs(int i, int j, int k){
    if(i >= j) return i == j;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    ll res = 0;
    if(S[i] == S[j]){
        res = dfs(i + 1, j - 1, k) + 2;
    }else{
        res = max(dfs(i, j - 1, k), dfs(i + 1, j, k));
        if(k != 0) res = max(res, dfs(i + 1, j - 1, k - 1) + 2);
    }
    return dp[i][j][k] = res;
}

int main() {
    cin>>S>>K;
    N = S.size();
    cout<<dfs(0, N - 1, K)<<endl;
}