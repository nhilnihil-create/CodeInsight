#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;
const int N = 8003;
string s;
int x, y;
vector <pii> a, b;
bool can[N][2 * N];
void make(string s, vector <pii> &a, vector <pii> &b) {
    try {
        a.clear(); b.clear();
        int cnt = 0, flip = 0;
        s += 'T';
        for (auto x: s) {
            if (x == 'T') {
                if (!flip) {
                    if (a.size() == 0)
                        a.push_back(make_pair(cnt, cnt));
                    else
                        a.push_back(make_pair(cnt, -cnt));
                }
                else b.push_back(make_pair(cnt, -cnt));
                cnt = 0;
                flip = 1 - flip;
            } else cnt++;
        }
    } catch (exception ex) {
        return;
    }
}
bool canReach(int des, vector <pii> c) {
    memset(can, 0, sizeof(can));
    can[0][N] = true;
    int n = c.size();
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2 * N; j++)
            if (can[i - 1][j]) {
                can[i][j + c[i - 1].first] = can[i][j + c[i - 1].second] = true;
            }
    }
    return can[n][des + N];
}
int main() {
    try {
        cin >> s >> x >> y;
        make(s, a, b);
        if (canReach(x, a) && canReach(y, b)) {
            cout << "Yes";
        } else cout << "No";
    } catch (exception ex) {
    }
    return 0;
}
