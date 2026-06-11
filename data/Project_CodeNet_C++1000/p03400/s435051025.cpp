#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d, x;
    cin >> n >> d >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a.at(i);

    int s = 0;
    for (int i = 0; i < n; i++)
        s += (d - 1) / a.at(i) + 1;

    cout << s + x << endl;
}