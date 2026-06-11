#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, len[max_n];

void write(const set<pair<int, int>> &q) {
    for (auto p : q) {
        cout << "(" << p.first << " " << p.second << ") ";
    }
    cout << endl;
}

bool check(int cnt) {
    set<pair<int, int>> q;
    int last_len = 0;
    for (int i = 0; i < n; ++i) {
        //cout << i << ": ";
        //write(q);
        if (last_len < len[i]) {
            last_len = len[i];
            continue;
        }
        while (!q.empty()) {
            pair<int, int> p = *q.rbegin();
            if (p.first > len[i]) {
                q.erase(p);
            } else {
                break;
            }
        }
        if (cnt == 1) {
            return false;
        }
        last_len = len[i];
        int pos = len[i], ok = 0;
        while (!q.empty()) {
            pair<int, int> p = *q.rbegin();
            if (p.first < pos) {
                q.insert({pos, 2});
                ok = 1;
                break;
            }
            q.erase(p);
            if (p.second < cnt) {
                ++p.second;
                q.insert(p);
                ok = 1;
                break;
            }
            --pos;
        }
        if (ok) {
            continue;
        }
        if (pos == 0) {
            return false;
        }
        q.insert({pos, 2});
    }
    //write(q);
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &len[i]);
    }
    //cout << check(2) << endl;
    //return 0;
    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%d\n", r);
    return 0;
}
