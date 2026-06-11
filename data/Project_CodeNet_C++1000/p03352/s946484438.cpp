#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int X; cin >> X;
    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 2; j <= 1000; j++) {
            int ex = pow(i, j);
            if (ex <= X) {
                ans = max(ans, ex);
            } else {
                break;
            }
        }
    }
    cout << ans << endl;
}
