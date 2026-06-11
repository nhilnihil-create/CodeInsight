#include <bits/stdc++.h>
using namespace std;

int main() {
    long long s;
    cin >> s;

    long long result = 1000, tmp;
    while (s >= 100) {
        tmp = 753 - (s % 1000);
        tmp = (tmp < 0 ? tmp * -1 : tmp);
        if (tmp < result) result = tmp;
        s /= 10;
    }

    cout << result << endl;

    return 0;
}
