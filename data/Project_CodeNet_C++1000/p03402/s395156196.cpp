#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b; a--; b--;
    cout << 100 << ' ' << 100 << '\n';
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 100; j++) {
            if (i % 2 && j % 2) {
                if (a) cout << '.', a--;
                else cout << '#';
            } else cout << '#';
        }
        cout << '\n';
    }
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 100; j++) {
            if (i % 2 && j % 2) {
                if (b) cout << '#', b--;
                else cout << '.';
            } else cout << '.';
        }
        cout << '\n';
    }
}
