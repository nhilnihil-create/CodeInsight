#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    cin >> x;
    vector<bool> count(1010, false);
    count.at(1) = true;
    for (int b = 2; b <= x; b++) {
        for (int p = 2; pow(b, p) <= x; p++) {
            count.at(int(pow(b, p))) = true;
        }
    }
    for (int i = x; i >= 1; i--) {
        if (count.at(i) == true) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
