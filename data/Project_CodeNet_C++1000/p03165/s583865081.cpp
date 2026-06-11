#include <bits/stdc++.h>
using namespace std;

string lcs(string a, string b) {
    if (a.size() > b.size())
        swap(a, b);
    int n = a.size();
    int m = b.size();
    vector<vector<string>> kek(2, vector<string>(n + 1));

    for (int j = 1; j <= m; ++j)
    for (int i = 1; i <= n; ++i)
        if (a[i - 1] == b[j - 1])
            kek[j % 2][i] = kek[(j + 1) % 2][i - 1] + a[i - 1];
        else {
            auto left = kek[j % 2][i - 1];
            auto up = kek[(j + 1) % 2][i];

            kek[j % 2][i] = left.size() > up.size()
                            ? left
                            : up;
        }

    return kek[m % 2][n];
}

int main(void) {
    string s, t;
    cin >> s >> t;
    cout << lcs(s, t) << endl;
}
