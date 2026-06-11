#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a.at(i);

    int cnt = 0;
    while (true) {
        bool can_operate = true;
        for (int i : a)
            if (i % 2 == 1) {
                can_operate = false;
                break;
            }

        if (!can_operate)
            break;

        cnt++;
        for (int i = 0; i < n; i++)
            a.at(i) /= 2;
    }

    cout << cnt << endl;
}