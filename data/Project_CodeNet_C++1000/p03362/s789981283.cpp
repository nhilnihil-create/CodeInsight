#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    int N;
    cin >> N;

    vi primes;
    for (int i = 2; i <= 55555; i++) {

        bool ok = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                ok = false;
                break;
            }
        }

        if (ok) {
            if (i % 5 == 1) {
                primes.push_back(i);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << primes[i];
        if (i != N - 1) cout << " ";
    }
    cout << endl;
}