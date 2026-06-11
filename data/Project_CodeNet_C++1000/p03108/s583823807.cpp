#include "bits/stdc++.h"

using namespace std;

vector<long long> parents;
vector<long long> sizes;

void init(long long n) {
    parents = vector<long long>(n, 0LL);
    sizes = vector<long long>(n, 1LL);
    for (long long i = 0; i < n; ++i) {
        parents[i] = i;
    }
}

long long find(long long x) {
    if (parents[x] == x) {
        return x;
    }
    else {
        parents[x] = find(parents[x]);
        return parents[x];
    }
}

void unite(long long x, long long y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return;
    }
    long long total = sizes[x] + sizes[y];
    if (sizes[x] > sizes[y]) {
        parents[y] = x;
    }
    else { // (sizes[y] >= sizes[x])
        parents[x] = y;
    }
    sizes[x] = total;
    sizes[y] = total;
}

bool same(long long x, long long y) {
    return find(x) == find(y);
}

void Main() {
    long long N, M;
    cin >> N >> M;
    vector<long long> A(M, 0), B(M, 0);
    for (long long i = 0; i < M; ++i) {
        cin >> A[i] >> B[i];
        A[i] -= 1LL;
        B[i] -= 1LL;
    }
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    init(N);
    vector<long long> ans(M, -1);
    ans[0] = N * (N - 1LL) / 2LL;
    for (long long i = 0; i < M - 1; ++i) {
        if (ans[i] == 0LL) {
            ans[i + 1] = 0LL;
        }
        else {
            if (!same(A[i], B[i])) {
                long long szA = sizes[find(A[i])];
                long long szB = sizes[find(B[i])];
                ans[i + 1] = ans[i] - szA * szB;
            }
            else {
                ans[i + 1] = ans[i];
            }
            unite(A[i], B[i]);
        }
    }
    reverse(ans.begin(), ans.end());

    for (long long i = 0; i < M; ++i) {
        cout << ans[i] << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
