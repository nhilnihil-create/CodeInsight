#include <iostream>
using namespace std;

int main() {
    int n,y;
    cin >> n >> y;
    int a= -1, b = -1, c = -1;
    for (int i = 0; i < n + 1; i++) {
        
        for (int j = 0; j < n - i + 1; j++) {
            int n_d = n - i - j;
            int total = 10000 * n_d + 5000 * j + 1000 * i;
            if (total == y) {
                a = n_d;
                b = j;
                c = i;
                cout << a << ' ' << b << ' ' << c << endl;
                return 0;
            }
        }
    }
    cout << a << ' ' << b << ' ' << c << endl;
    return 0;
}