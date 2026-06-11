#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    long ans = pow(N/K, 3);
    if (K%2 == 0) {
        ans += pow((2*N/K+1)/2, 3);
    }
    cout << ans << endl;
}