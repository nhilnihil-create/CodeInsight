#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    map<int, int> data;
    for (int x : a) {
        if (data.count(x)) {
            data.at(x)++;
        }

        else {
            data[x] = 1;
        }
    }
    vector<int> b;
    for (auto x : data) {
        b.push_back(x.second);
    }
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    int c = 0;
    if (b.size() < k) {
        cout << 0 << endl;
    }

    else {
        for (int i = 0; i < k; i++) {
            c += b.at(i);
        }

        cout << n - c << endl;
    }
}