#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
}

int main() {
    int N, max = 1; cin >> N;
    vector<int> A(N, 0), L(N, 0), R(N, 0), gcds(N, 0); // L[i]はA[0]からA[i]までの最大公約数、R[i]はA[i]からA[N - 1]までの最大公約数
    for(int i = 0; i < N; i++) cin >> A[i];
    L[0] = A[0]; R[N - 1] = A[N - 1];
    for(int i = 1; i < N; i++) {
        L[i] = gcd(L[i - 1], A[i]); R[N - 1 - i] = gcd(R[N - i], A[N - 1 - i]);
    }
    gcds[0] = R[1]; gcds[N - 1] = L[N - 2];
    for(int i = 1; i < N - 1; i++) gcds[i] = gcd(L[i - 1], R[i + 1]);
    for(int i = 0; i < N; i++) {
        if(max < gcds[i]) max = gcds[i];
    }
    cout << max << endl;
    return 0;
}