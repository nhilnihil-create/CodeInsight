#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1LL << 60;

void solve(){
    vector<vector<int>> G(4);
    vector<int> R(4);
    for(int i = 0; i < 3; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < 4; i++)R[i] = G[i].size();
    sort(R.begin(), R.end());
    if(R[0] == 1 && R[1] == 1 && R[2] == 2 && R[3] == 2)printf("YES\n");
    else printf("NO\n");
    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}