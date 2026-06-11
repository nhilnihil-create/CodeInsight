#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    int count = 0;

    for (int used_a = 0; used_a <= a; used_a++) {
        for (int used_b = 0; used_b <= b; used_b++) {
            int temp = x - (500 * used_a + 100 * used_b);
            if (temp >= 0 && temp % 50 == 0 && temp / 50 <= c) {
                count++;
                //cout << used_a << ' ' << used_b << ' ' << temp / 50 << endl;
            }
        }
    }
    
    cout << count << endl;
}