#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void) {
    int n, i, j;

    cin >> n;

    cout << n / 2 * (n / 2 - 1) * 2 + n / 2 * 2 * (n & 1) << endl;

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (j != (n + 1 - n % 2) - i) {
                cout << i << ' ' << j << endl;
            }
        }
    }

    return 0;
}