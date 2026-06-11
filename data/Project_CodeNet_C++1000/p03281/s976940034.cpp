#include <iostream>
using namespace std;
int main () {
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i += 2) {
        int k = 0;
        for (int j = 1; j <= N; ++j) {
            if (i % j == 0) { k++; }
        }
        if (k == 8) {
            ans++;
        }
    }
    cout << ans << "\n";
}
