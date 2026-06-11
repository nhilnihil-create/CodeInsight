#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int mod = 1e9 + 7;

int power(int a, int n){
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        int b = power(a, n / 2);
        return 1ll * b * b % mod;
    } else {
        return 1ll * a * power(a, n - 1) % mod;
    }
}

int inverse(int a) {
    if (a == 1) {
        return 1;
    }
    return power(a, mod - 2);
}

int factorial(int N) {
    if (N == 0) {
        return 1;
    } else {
        return 1ll * N * factorial(N - 1) % mod;
    }
}

int main() {
    cin >> N;
    vector<int> A(N), B(N, 1);  //B[i]: 1/(i+1)までの和
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i > 0) {
            B[i] = (B[i - 1] + inverse(i + 1)) % mod;
        }
    }
    
    long long answer = 0ll;
    for (int i = 0; i < N; i++) {
        answer += 1ll * (B[i] + B[N - i - 1] - 1) * A[i] % mod;
        answer %= mod;
    }
    
    cout << answer * factorial(N) % mod << endl;
}