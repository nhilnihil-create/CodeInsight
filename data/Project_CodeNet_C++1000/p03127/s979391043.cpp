#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int gcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    if (a % b) {
        return gcd(b, a % b);
    } else {
        return b;
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i < N; i++) {
        A[i] = gcd(A[i - 1], A[i]);
    }
    cout << A[N - 1] << endl;
    return 0;
}