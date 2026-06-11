#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

struct Review {
    int idx;
    string city;
    int point;
};

bool comp(Review r1, Review r2) {
    if (r1.city == r2.city) {
        return r1.point > r2.point;
    } else {
        return r1.city < r2.city;
    }
}

int main() {
    int n;
    cin >> n;
    Review r[n];

    rep(i, n) {
        string s;
        int p;
        cin >> s >> p;
        r[i].city = s;
        r[i].point = p;
        r[i].idx = i + 1;
    }

    sort(r, r + n, comp);

    for (auto e : r) cout << e.idx << endl;
    return 0;
}
