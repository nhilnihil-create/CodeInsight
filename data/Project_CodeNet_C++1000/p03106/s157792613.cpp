#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int a, b, k;
    cin >> a >> b >> k;

    vector<int> x;
    for (int i = 1; i <= a; i++) {
        if (a%i == 0 && b%i == 0) {
            x.push_back(i);
        }
    }

    reverse(x.begin(), x.end());
    cout << x[k-1] << endl;
    return 0;
}