#include <bits/stdc++.h>
using namespace std;

int main(void) {
    vector<long long> cookie(2);
    int K;
    cin >> cookie[0] >> cookie[1] >> K;
    for (int i = 0; i < K; i++) {
        if (cookie[i % 2] % 2 == 1) {
            cookie[i % 2] -= 1;
        }
        cookie[(i + 1) % 2] += cookie[i % 2] / 2;
        cookie[i % 2] /= 2;
    }
    cout << cookie[0] << " " << cookie[1] << endl;
    return 0;
}