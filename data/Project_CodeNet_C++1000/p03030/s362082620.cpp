#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    struct Restaurant {
        string city;
        int score, id;
        // 比較関数が必要
        bool operator<(const Restaurant &rhs) {
            return (this->city < rhs.city) ||
                (this->city == rhs.city && this->score >= rhs.score);
        }
    };

    vector<Restaurant> rs(n);
    for (int i = 0; i < n; ++i) {
        cin >> rs[i].city >> rs[i].score;
        rs[i].id = i + 1;
    }

    sort(rs.begin(), rs.end());

    for (const auto &r : rs)
        cout << r.id << '\n';

    return 0;
}