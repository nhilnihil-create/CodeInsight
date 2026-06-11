#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a.at(i);

    sort(a.begin(), a.end());

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        x -= a.at(i);

        if (x < 0)
            break;
        else
            cnt++;
    }

    if (x > 0)
        cnt--;

    cout << cnt << endl;
}