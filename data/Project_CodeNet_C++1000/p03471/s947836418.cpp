#include <iostream>
using namespace std;

int main() {
    int n,y;
    cin >> n >> y;
    int a= -1, b = -1, c = -1;
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n - i + 1; j++) {
            int n_d = n - i - j;
            int total = 10000 * i + 5000 * j + 1000 * n_d;
            if (total == y) {
                a = i;
                b = j;
                c = n_d;
            }
        }
    }
    cout << a << ' ' << b << ' ' << c << endl;
}