#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;
constexpr int MN = 1e5+5;

ll L[MN], R[MN], A[MN], B[MN], ans;

int main() {
    if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);

    int N; cin >> N;
    for (int i = 0; i < N; ++i) cin >> L[i] >> R[i];
    sort(L, L+N, greater<ll>()), sort(R, R+N);
    for (int i = 0; i < N; ++i) A[i+1] = L[i]+A[i], B[i+1] = R[i]+B[i];
    for (int i = 0; i < N; ++i) ans = max({ A[i]-B[i+1], A[i+1]-B[i], A[i+1]-B[i+1], ans });
    cout << 2*ans;
}
