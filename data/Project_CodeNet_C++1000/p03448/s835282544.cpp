#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, x;
    cin >> a >> b >> c >> x;
    int res = 0;
    for (int e = 0; e <= a; ++e) {
        for (int f = 0; f <= b; ++f) {
            for (int g = 0; g <= c; ++g) {
                
                int tortal = 500 * e + 100 * f + 50 * g;
                if (x == tortal) res++;
            }
        }
    }
    cout << res << endl;
}