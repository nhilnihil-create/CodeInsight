#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<tuple<int, string, int>> v(n);
    for (int i = 0; i < n; i++) {
        string s;
        int p;
        cin >> s >> p;
        v.at(i) = make_tuple((i + 1), s, p);
    }

    sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
        string x = get<1>(a), y = get<1>(b);
        if (x == y)
            return get<2>(a) > get<2>(b);
        else
            return x < y;
    });

    for (const auto &x : v)
        cout << get<0>(x) << endl;
}