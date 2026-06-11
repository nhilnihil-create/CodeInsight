#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1LL << 60;

void solve(){
    int N, K;
    scanf("%d%d", &N, &K);
    int M = (N + 1) / 2;
    printf((M >= K) ? "YES\n" : "NO\n");
    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}