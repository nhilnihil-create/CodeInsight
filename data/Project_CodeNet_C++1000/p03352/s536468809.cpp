#include <bits/stdc++.h>
using namespace std;

int main() {
    int X;
    cin >> X;

    vector<int> v;
    v.push_back(1);
    for (int i = 2; i < 40; i++) {
        for (int j = 2; j < 10; j++) {
            int n = pow(i, j);
            if (n > X) break;
            v.push_back(n);
        }
    }

    sort(v.begin(), v.end(), greater<int>());

    cout << v[0] << endl;
}