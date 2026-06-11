#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int max_a = a[max_element(a, a + n) - a];
    int b[n];
    for (int i = 0; i < n; i++) {
        b[i] = (a[i] == max_a) ? -1 : min(max_a - a[i], a[i]);
    }
    int max_b = a[max_element(b, b + n) - b];
    cout << max_a << ' ' << max_b << endl;
    return 0;
}
