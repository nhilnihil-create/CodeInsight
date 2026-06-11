#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    if (n % 2 == 0) {
        return n / 2;
    }
    return 3 * n + 1;
}

int main(void) {
    int s;
    cin >> s;
    vector<int> a;
    vector<int> cnt(1e6 + 1);
    a.push_back(s);
    cnt.at(s)++;
    for (int i = 1;; i++) {
        int ai = f(a.back());
        a.push_back(ai);
        cnt.at(ai)++;
        for (int ii = 0; ii <= 1e6; ii++) {
            if (cnt.at(ii) > 1) {
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
    return 0;
}