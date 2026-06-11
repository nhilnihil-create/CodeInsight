#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int A, B, K;
    cin >> A >> B >> K;
    int m = A < B ? A : B;
    int cdiv = 0;
    for (int i = m; true; i--) {
        if (A % i == 0 && B % i == 0) cdiv++;
        if (cdiv == K) {
            cout << i << endl;
            return 0;
        }
    }
}