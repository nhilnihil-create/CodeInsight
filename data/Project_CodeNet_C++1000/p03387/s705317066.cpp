#include <bits/stdc++.h>
using namespace std;

int main() {
    int x[3];
    for (int i = 0; i < 3; i++) {
        cin >> x[i];
    }
    sort(x, x + 3);
    int count = 0;
    for (int i = 0; x[0] + 2 <= x[2]; i++) {
        x[0] += 2;
        count++;
    }
    for (int i = 0; x[1] + 2 <= x[2]; i++) {
        x[1] += 2;
        count++;
    }
    if (2 * x[2] - x[0] - x[1] == 1) count += 2;
    if (2 * x[2] - x[0] - x[1] == 2) count += 1;
    cout << count << endl;
}