// Si = A0 + A1 + ... + A(i-1)として、
// (i < j)で Sj = Si となる(i,j)の組み合わせを求める。
// 要素{Si}の配列を作って、ソートして、Pj個の同じ値の要素について、
// (Pj-1)*Pj/2を足していく
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<long long> S(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        S[i] = S[i - 1] + A[i - 1];
    }
    /*
    for (auto p : S) cout << p << " ";
    cout << endl;
    */
    sort(S.begin(), S.end());
    /*
    for (auto p : S) cout << p << " ";
    cout << endl;
    */
    long long ans = 0;
    long long len = 1;
    for (int i = 0; i <= N; ++i) {
        if (i == N) {
            ans += len * (len - 1) / 2;
            continue;
        }
        if (S[i] != S[i + 1]) {
            ans += len * (len - 1) / 2;
            len = 1;
        } else {
            ++len;
        }
    }
    cout << ans << endl;
    return 0;
}