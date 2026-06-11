#include <iostream>
#include <vector>

using namespace std;
#define ll long long

vector<int> par, rnk, mem;
int g;
void init(int n) {
    g = n;
    par.clear();
    rnk.clear();
    mem.clear();
    par.resize(n);
    rnk.resize(n);
    mem.resize(n);
    for(int i = 0; i < n; i++) {
        par[i] = i;
        rnk[i] = 0;
        mem[i] = 1;
    }
}
int find(int x) {
    if(par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) {
        return;
    } else {
        if(rnk[x] < rnk[y]) {
            par[x] = y;
            mem[y] += mem[x];
        } else {
            par[y] = x;
            mem[x] += mem[y];
            if(rnk[x] == rnk[y]) rnk[x]++;
        }
    }
    g--;
}
bool same(int x, int y) {
    return find(x) == find(y);
}
int size(int x) {
    return mem[find(x)];
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for(int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
    vector<ll> ans(M + 1, 0);
    ans[M] = (ll)N * ((ll)N - 1) / 2;
    init(N);
    for(int i = M - 1; i >= 0; i--) {
        if(same(A[i], B[i])) {
            ans[i] = ans[i + 1];
        } else {
            ans[i] = ans[i + 1] - (ll)size(A[i]) * (ll)size(B[i]);
            unite(A[i], B[i]);
        }
    }
    for(int i = 0; i < M; i++) {
        cout << ans[i + 1] << endl;
    }
    return 0;
}