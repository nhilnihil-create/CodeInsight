#include <iostream>
#include <utility>
#include <vector>
using namespace std;

bool reachable(int idx, int n, const vector<pair<char, char>>& magic,
               string s) {
    for (int i = 0; i < magic.size(); i++) {
        if (s[idx] == magic[i].first) {
            if (magic[i].second == 'L') idx--;
            if (magic[i].second == 'R') idx++;
        }
        if (idx == n) return true;
    }
    return false;
}

int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<pair<char, char>> magic(q);
    for (int i = 0; i < q; i++) {
        cin >> magic[i].first >> magic[i].second;
    }
    int dieLeft = -1;
    if (reachable(0, -1, magic, s)) {  // reach -1
        if (reachable(n - 1, -1, magic, s)) {
            dieLeft = n - 1;
        } else {
            int ok = 0;
            int ng = n - 1;
            while (abs(ng - ok) > 1) {
                int mid = (ok + ng) / 2;
                if (reachable(mid, -1, magic, s)) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            dieLeft = ok;
        }
    }
    int dieRight = n;
    if (reachable(n - 1, n, magic, s)) {  // reach n
        if (reachable(0, n, magic, s)) {
            dieRight = 0;
        } else {
            int ok = n - 1;
            int ng = 0;
            while (abs(ng - ok) > 1) {
                int mid = (ok + ng) / 2;
                if (reachable(mid, n, magic, s)) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            dieRight = ok;
        }
    }
    cout << n - min(n, dieLeft + 1 + n - dieRight) << endl;
}