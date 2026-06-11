#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N, M;
LL X[100000];

int main() {
    scanf("%d%d", &N, &M);
    rep(i, M) scanf("%lld", &X[i]);
    sort(X, X + M);
    rep(i, M - 1) X[i] = X[i + 1] - X[i];
    sort(X, X + M - 1);
    LL ans = 0;
    rep(i, M - N) ans += X[i];
    printf("%lld\n", ans);
    return 0;
}