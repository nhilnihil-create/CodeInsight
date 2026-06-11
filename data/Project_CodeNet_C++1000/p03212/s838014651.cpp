#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll ans;
ll N;

void dfs(ll now, int use, ll &ans){
    if(now > N)return;
    if(use == 0b111)ans++;

    dfs(now*10+7, use | 0b001, ans);
    dfs(now*10+5, use | 0b010, ans);
    dfs(now*10+3, use | 0b100, ans);
}

int main() {
    cin >> N;
    dfs(0, 0, ans);

    cout << ans << endl;


    return 0;
}