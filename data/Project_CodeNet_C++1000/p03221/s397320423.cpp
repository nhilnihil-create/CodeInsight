#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int M, N; scanf("%d%d", &M, &N);
    int X[100000][2]; rep(i, N) rep(j, 2) scanf("%d", &X[i][j]);
    int P[100000]; rep(i, N) P[i] = i;
    auto cmpX = [&X](int l, int r)->bool {
        return make_pair(X[l][0], X[l][1]) < make_pair(X[r][0], X[r][1]);
    };
    sort(P, P + N, cmpX);
    LL ans[100000]; int p = 0, pp = -1;
    rep(i, N) {
        ans[P[i]] = (LL)X[P[i]][0] * 1000000;
        if (X[P[i]][0] != pp) { p = 0; pp = X[P[i]][0]; }
        p++;
        ans[P[i]] += p;
    }

    rep(i, N) printf("%.12lld\n", ans[i]);

    return 0;
}