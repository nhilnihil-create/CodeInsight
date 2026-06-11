#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const int MN = 200010;

int N, X;
int A[MN];
ll psum[MN];

int f(int cnt) {
    if(cnt == 1) return 5;
    else return 2 * cnt + 1;
}
ll calc(int l, int r) {
    return psum[r] - (l? psum[l - 1] : 0);
}

int main() {
    scanf("%d %d", &N, &X);

    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < N; i++) {
        psum[i] = A[i];
        if(i) psum[i] += psum[i - 1];
    }

    ll ans = 1e19;
    for(int i = 1; i <= N; i++) {
        ll sum = 0;
        int cnt = 1;
        for(int j = N - 1; j >= 0; j -= i) {
            sum += calc(max(0, j - i + 1), j) * f(cnt);
            cnt++;
        }
        ans = min(ans, sum + i * X);
    }
    cout << ans + 1LL * N * X;
}
