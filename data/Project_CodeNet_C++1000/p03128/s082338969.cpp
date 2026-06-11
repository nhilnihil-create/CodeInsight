# include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int def[10] = {-100000, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    int n, m; cin >> n >> m;
    int a[m];
    vector<pair<int, int>> hand(m); // num, cost
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        hand[i] = {a[i], def[a[i]]};
    }
    sort(hand.begin(), hand.end(), greater<>());
    int mnv = hand[0].first, mnc = hand[0].second;
    for (int i = 1; i < m; i++) {
        int cost = hand[i].second;
        int val = hand[i].first;
        if (mnc > cost) {
            mnc = cost;
            mnv = val;
        }
    }
    int order = n/mnc;

    vector<string> s;
    for (int ord = order; ord >= 1; ord--) {
        string ans = "";
        for (int i = 0; i < ord; i++) {
            ans += to_string(mnv);
        }
        int left = n - mnc * ord;
        queue<pair<int, string>> q;
        q.push({left, ans});
        bool flag = false;
        while (!q.empty()) {
            int fl = q.front().first;
            string fs = q.front().second;
            q.pop();
            if (fl == 0) {
                flag = true;
                s.push_back(fs);
            }
            // find included unique number
            set<char> uniH;
            for (auto &c : fs) {
                uniH.insert(c);
            }
            for (auto it = uniH.begin(); it != uniH.end(); it++) {
                for (int i = 0; i < m; i++) {
                    string ns(fs);
                    ns[ns.find(*it)] = to_string(hand[i].first)[0];
                    int diff = hand[i].second - def[*it - '0'];
                    if (diff > 0 && fl - diff >= 0) {
                        sort(ns.begin(), ns.end(), greater<>());
                        q.push({fl - diff, ns});
                    }
                }
            }
        }
        if (flag) break;
    }
    sort(s.begin(), s.end());
    cout << s.back() << endl;
    return 0;
}
