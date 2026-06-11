#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printVector(vector<int> v) {
    for (auto x : v) {
        cout << x << ' ';
    }
    cout << '\n';
}

void printArray(ll A[], int size) {
    for (int i = 0; i <= size - 1; i++) cout << A[i] << ' ';
}

int main() {
    int n;
    cin >> n;
    ll A[n];
    for (int i = 0; i <= n - 1; i++) cin >> A[i];
    //printArray(A, n);
    ll L[n];
    ll R[n];
    L[0] = A[0];
    R[n - 1] = A[n - 1];
    for (int i = 1; i <= n - 1; i++) {
        L[i] = __gcd(L[i - 1], A[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        R[i] = __gcd(R[i + 1], A[i]);
    }
    //printArray(L, n);
    //cout << '\n';
    //printArray(R, n);
    ll M[n];
    M[0] = R[1];
    M[n - 1] = L[n - 2];
    for (int i = 1; i <= n - 2; i++) {
        M[i] = __gcd(L[i - 1], R[i + 1]);
    }
    ll ans = 1;
    for (int i = 0; i <= n - 1; i++) {
        ans = max(ans, M[i]);
    }
    cout << ans << '\n';
    return 0;
}