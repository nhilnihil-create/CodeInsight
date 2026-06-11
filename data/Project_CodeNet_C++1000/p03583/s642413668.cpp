#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main() {
    ll N;
    cin >> N;
    for (int h = 1; h <= 3500; h++) {
        for (int n = 1; n <= 3500; n++) {
            if (4 * h * n > N * (h + n) && N * h * n % (4 * h * n - N * (h + n)) == 0) {
                cout << h << " " << n << " " << N * h * n / (4 * h * n - N * (h + n)) << endl;
                return 0;
            }
        }
    }
    return 0;
}