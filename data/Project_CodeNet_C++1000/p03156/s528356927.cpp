#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int g1 = 0, g2 = 0, g3 = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (p <= a) g1++;
        else if (p <= b) g2++;
        else g3++;
    }
    cout << min({g1, g2, g3}) << endl;
}