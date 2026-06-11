#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
int n;
ll ans = 0;
void dfs(ll now, ll a, ll b, ll c) {
    if(now > n) return;
    if(a && b && c) ans++;
    dfs(now*10+3, 1, b, c);
    dfs(now*10+5, a, 1, c);
    dfs(now*10+7, a, b, 1);
}

int main() {
    cin >> n;
    dfs(0, 0, 0, 0);
    cout << ans << endl;
    return 0;
}