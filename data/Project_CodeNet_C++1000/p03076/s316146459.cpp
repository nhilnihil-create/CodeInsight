#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(5);
    int min = 10, sum = 0, tmp = 0;
    for (int i = 0; i < 5; i++) {
        cin >> a.at(i);
        if (a.at(i) % 10 < min && a.at(i) % 10 != 0) min = a.at(i) % 10;
        if (a.at(i) % 10 == 0) {
            sum += a.at(i);
        } else {
            sum += a.at(i) + 10 - (a.at(i) % 10);
        }
    }

    if (min >= 10) {
        cout << sum << endl;
    } else {
        cout << sum - (10 - min) << endl;
    }

    return 0;
}
