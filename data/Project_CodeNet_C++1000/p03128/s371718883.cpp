#include <bits/stdc++.h>
using namespace std;

bool comp(string s, string t, int num) {
    if (s.size() != t.size() + 1) return s.size() < t.size() + 1;

    t += to_string(num);
    for (int i = 0; i < (int)s.size(); i++) {
        if (s.at(i) != t.at(i)) return s.at(i) < t.at(i);
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a.at(i);
    }
    sort(a.rbegin(), a.rend());
    const vector<int> num_use = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    vector<string> dp(n + 1, "0");
    dp.at(n) = "";

    for (int i = 0; i < m; i++) {
        int x = a.at(i);
        for (int j = n; j >= 2; j--) {
            if (dp.at(j) == "0") continue;
            
            if (0 <= j - num_use.at(x)) {
                if (comp(dp.at(j - num_use.at(x)), dp.at(j), x)) {
                    dp.at(j - num_use.at(x)) = dp.at(j) + to_string(x);
                }
            }
        }
    }
    cout << dp.at(0) << endl;
}  