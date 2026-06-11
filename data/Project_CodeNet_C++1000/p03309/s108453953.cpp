#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        A[i] -= i;
    }

    //絶対値の和の最小化＝＞メジアンで最小！！
    //奇数の時も偶数の時もsortedのN/2+1番目の値が最小となる
    sort(A.begin(), A.end());
    ll x = A[N/2];

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(A[i]-x);
    }

    cout << ans << endl;
}