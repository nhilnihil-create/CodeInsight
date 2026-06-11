#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}



int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    int Y = 1e9;
    for(int i=0; i<N-1; i++) {
        Y = min(Y, gcd(A[i], A[i+1]));
    }
    cout << Y << endl;
}