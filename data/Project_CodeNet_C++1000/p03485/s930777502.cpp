#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, mean;
    int ans;

    cin >> a >> b;

    mean = (a + b) / 2;
    mean += 0.5;
    ans = int(mean);

    cout << ans << endl;
}
