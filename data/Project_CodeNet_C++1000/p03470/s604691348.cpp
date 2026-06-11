#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d.at(i);

    sort(d.begin(), d.end());
    reverse(d.begin(), d.end());

    int c = 1, tmp = d.at(0);
    for (int i = 1; i < n; i++) {
        if (tmp > d.at(i)) {
            tmp = d.at(i);
            c++;
        }
    }

    cout << c << endl;

    return 0;
}
