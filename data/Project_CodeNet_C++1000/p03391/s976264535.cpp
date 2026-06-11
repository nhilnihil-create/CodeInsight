#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    ll s = 0, minB = 1e18;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        if (A[i] > B[i]) minB = min(minB, B[i]);
        s += A[i];
    }
    cout << (minB == 1e18 ? 0 : s - minB) << endl;
    return 0;
}