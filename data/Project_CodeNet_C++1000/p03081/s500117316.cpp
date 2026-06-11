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

int binary(int ok, int ng, int n, const vector<pair<char, char>>& magic,
           string s) {
    while (abs(ng - ok) > 1) {
        int mid = (ok + ng) / 2;
        if (reachable(mid, n, magic, s)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<pair<char, char>> magic(q);
    for (int i = 0; i < q; i++) {
        cin >> magic[i].first >> magic[i].second;
    }
    int dieLeft = binary(-1, n, -1, magic, s);
    int dieRight = binary(n, -1, n, magic, s);
    cout << n - min(n, dieLeft + 1 + n - dieRight) << endl;
}