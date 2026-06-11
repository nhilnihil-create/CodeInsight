#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        sum += a.at(i);
    }
    double m = (double)sum / n;

    int index = 0;
    double d = 10000;
    for (int i = 0; i < n; i++) {
        if (abs(m - a.at(i)) < d) {
            index = i;
            d = abs(m - a.at(i));
        }
    }

    cout << index << endl;
}