#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

struct Ans {
    int N;
    int M;
    int u[60];
    int v[60];
    int w[60];
};

struct Ans solve(int L) {
    struct Ans ret;
    if (L < 3) {
        ret.N = 2;
        ret.M = L;
        rep(i, L) {
            ret.u[i] = 0;
            ret.v[i] = 1;
            ret.w[i] = i;
        }
        return ret;
    }
    if (L % 2 == 1) {
        ret = solve(L - 1);
        ret.u[ret.M] = 0;
        ret.v[ret.M] = ret.N - 1;
        ret.w[ret.M] = L - 1;
        ret.M++;
    } else {
        ret = solve(L / 2);
        ret.u[ret.M] = ret.N - 1;
        ret.v[ret.M] = ret.N;
        ret.w[ret.M] = 0;
        ret.u[ret.M + 1] = ret.N - 1;
        ret.v[ret.M + 1] = ret.N;
        ret.w[ret.M + 1] = L / 2;
        ret.N++;
        ret.M += 2;
    }
    return ret;
}

int main() {
    int L;
    cin >> L;
    struct Ans a = solve(L);
    cout << a.N << " " << a.M << endl;
    rep(i, a.M) cout << a.u[i] + 1 << " " << a.v[i] + 1 << " " << a.w[i] << endl;
}
