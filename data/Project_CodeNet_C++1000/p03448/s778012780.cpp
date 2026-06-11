#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    int x;
    cin >> x;
    int now;
    int cnt = 0;
    for (int i = 0; i < a + 1; i++) {
        for (int j = 0; j < b + 1; j++) {
            now = x - (500 * i + 100 * j);
            
            if (now  > 0) {
                if (now / 50 <= c) {
                    if (now - now / 50 * 50 == 0) cnt++;
                }
            }
            else if (now == 0) cnt++;
        }
    }

    cout << cnt << endl;
}