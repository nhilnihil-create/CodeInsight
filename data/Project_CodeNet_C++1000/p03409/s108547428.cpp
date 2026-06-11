#include <bits/stdc++.h>
using namespace std;

bool compare_by_x(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main() {
    int N;
    cin >> N;
    int x, y;
    vector<pair<int, int> > red, blue;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        red.push_back(make_pair(x, y));
    }
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        blue.push_back(make_pair(x, y));
    }
    sort(blue.begin(), blue.end(), compare_by_x);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int res = -1;
        for (int j = 0; j < red.size(); ++j) {
            if (red[j].second < blue[i].second && red[j].first < blue[i].first) {
                if (res == -1) {
                    res = j;
                } else {
                    if (red[res].second < red[j].second) { res = j; }
                }
            }
        }
        if (res != -1) {
            red[res] = red.back();
            red.erase(red.end());
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}