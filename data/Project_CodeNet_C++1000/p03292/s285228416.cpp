#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(3), w(3);
    for (int i = 0; i < 3; ++i) cin >> v[i];
    for (int i = 0; i < 3; ++i) w[i] = abs(v[i] - v[(i + 1) % 3]);
    cout << accumulate(w.begin(), w.end(), 0LL) - *max_element(w.begin(), w.end()) << endl;
}
