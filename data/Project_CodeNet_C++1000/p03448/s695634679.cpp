#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    int ans = 0;
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            int sum = x - 500 * i - 100 * j;
            if (0 <= sum && sum <= 50 * c && sum%50 == 0) ans++;
        }
    }
    cout << ans << endl;
}