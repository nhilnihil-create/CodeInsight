#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;
int dp[3010][3010];
string a, b, ans;
int f(int i, int j){
    if(i == a.size() || j == b.size()) return 0;
    int &ans = dp[i][j];
    if(dp[i][j] == -1){
        if(a[i] == b[j]) ans = max(ans, f(i + 1, j + 1) + 1);
        else ans = max(f(i + 1, j), f(i, j + 1));
    }
    return ans;
}
void build(int i,int j){
    if(i == a.size() || j == b.size())return;
    ll answer = f(i, j);
    if(a[i] == b[j] && answer == f(i + 1, j + 1) + 1){
        ans.push_back(a[i]);
        build(i + 1, j + 1);
    }
    else if(answer == f(i + 1, j))build(i + 1, j);
    else if(answer == f(i, j + 1))build(i, j + 1);
    return;
}
int main(){
    fast;
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    ans.clear();
    f(0, 0);
    build(0, 0);
    cout << ans << "\n";
    return 0;
}
