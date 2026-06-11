#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    if (n == 3) {
        cout << 2 << " " << 5 << " " << 63 << endl;
        return 0;
    }
    for (int i = 2; i < n; i += 2){
        if (n - i <= 15000 && (n - i) % 3 != 1) {
            for (int j = 1; j <= i; j++)
                cout << (j - 1) * 6 + 3 << " ";
            for (int j = 1; j <= n - i; j++)
                cout << 2 * j << " ";
            return 0;
        }
    }
}