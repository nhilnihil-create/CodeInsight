#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> m(n);
    int remain = x, cnt = n;
    for(int i = 0; i < n; i++) {
        cin >> m[i];
        remain -= m[i];
    }

    sort(m.begin(), m.end());

    for(int i = 0; i < n; i++) {
        cnt += remain / m[i];
        remain %= m[i];
    }

    cout << cnt << endl;

    return 0;
}