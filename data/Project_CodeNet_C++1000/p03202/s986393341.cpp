#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[200000];

void normalize(vector<pair<int, int>> &a) {
    while (a.size() >= 2) {
        if (a[a.size() - 1].first == a[a.size() - 2].first) {
            a[a.size() - 2].second += a[a.size() - 1].second;
            a.pop_back();
        } else break;
    }
}

bool f(int x) {
    vector<pair<int, int>> s;
    s.emplace_back(0, a[0]);
    for (int i = 0; i + 1 < n; i++) {
        int d = max(0, a[i] - a[i + 1]);
        while (d > 0) {
            if (d >= s.back().second) {
                d -= s.back().second;
                s.pop_back();
            } else {
                s.back().second -= d;
                d = 0;
            }
        }
        if (a[i] >= a[i + 1]) {
            if (s.back().first < x - 1) {
                auto p = s.back();
                s.pop_back();
                if (p.second > 1) {
                    s.emplace_back(p.first, p.second - 1);
                }
                s.emplace_back(p.first + 1, 1);
            } else {
                auto p = s.back();
                s.pop_back();
                if (s.empty()) return false;
                auto q = s.back();
                s.pop_back();
                if (q.second > 1) {
                    s.emplace_back(q.first, q.second - 1);
                }
                s.emplace_back(q.first + 1, 1);
                normalize(s);
                s.emplace_back(0, p.second);
            }
        } else {
            s.emplace_back(0, a[i + 1] - a[i]);
        }
        normalize(s);
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0;
    int r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (f(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;
}

