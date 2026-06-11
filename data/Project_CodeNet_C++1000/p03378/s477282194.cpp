#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<int> a_i(m);
    for (int i = 0; i < m; i++)
        cin >> a_i.at(i);

    sort(a_i.begin(), a_i.end());

    int j;
    for (j = 0; j < m - 1; j++)
        if (a_i.at(j) < x && x < a_i.at(j + 1))
            break;

    cout << min(j + 1, m - 1 - j) << endl;
}