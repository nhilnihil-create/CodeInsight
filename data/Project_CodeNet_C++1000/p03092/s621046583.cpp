#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 5001;

int n, A, B, cnt[N];
ll dp[N][N];
vector <int> a;

ll solve(int idx, int j){
    if(idx == n) return 0;
    ll &ret = dp[idx][j];
    if(ret != -1) return ret;
    if(a[idx] == j) return solve(idx + 1, j + 1);
    if(a[idx] < j) return solve(idx + 1, j);
    if(cnt[j]) return solve(idx, j + 1);
    ret = solve(idx, j + 1) + B;
    cnt[a[idx]]++;
    ret = min(ret, solve(idx + 1, j) + A);
    cnt[a[idx]]--;
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> A >> B;
    a.resize(n);
    for(auto &i : a) cin >> i;
    cout << solve(0, 1) << endl;
}
