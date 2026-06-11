#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N;
    cin >> N;
    int M = 1e6;
    vector<int> isPrime(M, true);
    isPrime[0] = false;
    isPrime[1] = false;
    isPrime[2] = true;
    for (int k = 2; k < M; k++) {
        if (!isPrime[k])
            continue;

        for (int l = 2; k * l < M; l++) {
            isPrime[k * l] = false;
        }
    }

    vector<int> ans;
    for (int i = 0; i < M; i++) {
        if (isPrime[i] && i % 5 == 1) {
            ans.push_back(i);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
