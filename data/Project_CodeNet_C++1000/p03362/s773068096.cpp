#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    vi pri;
    for (int i = 2; i < 55555; i++) {
        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime && (i % 5 == 1)) {
            pri.push_back(i);
        }
    }

    int N;
    cin >> N;
    rep(i, N) {
        cout << pri[i];
        if (i != N - 1) cout << " ";
    }
    cout << endl;
}