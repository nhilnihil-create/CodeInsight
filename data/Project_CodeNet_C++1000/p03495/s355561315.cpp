#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N+1);
    for(int i=0; i<N; i++) {
        int a;
        cin >> a;
        A[a]++;
    }

    ll ans = 0;
    sort(A.begin(), A.end());

    for(int i=0; i<=N-K; i++) {
        ans += A[i];
    }
    cout << ans << endl;
}