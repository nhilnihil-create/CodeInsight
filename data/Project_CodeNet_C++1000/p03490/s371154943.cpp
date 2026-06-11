#include <bits/stdc++.h>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string s;
int gx, gy;
bool valid(int x) { return (0 <= x && x < 16004); }
bool ok(int goal, vector<int> vec, bool first=false) {
    vector<int> cur(16004), next(16004);
    cur[8002] = true;

    rep(i, vec.size()) {
        rep(j, 16004) {
            if (valid(j + vec[i])) next[j + vec[i]] |= cur[j];
            if (!first && valid(j - vec[i])) next[j - vec[i]] |= cur[j];
        }
        first = false;
        cur.swap(next);
        next.clear();
        next.resize(16004);
    }
    return cur[goal];
}
int main() {
    cin >> s >> gx >> gy;
    gx += 8002;
    gy += 8002;
    int cnt = 0;
    int cnt_dir = 0;
    vector<int> vec[2];
    rep(i, s.size()) {
        if (s[i] == 'F') {
            cnt++;
        } else {
            vec[cnt_dir % 2].push_back(cnt);
            cnt = 0;
            cnt_dir++;
        }
    }
    if (cnt) vec[cnt_dir % 2].push_back(cnt);
    bool ans = true;
    ans &= ok(gx, vec[0], true);
    ans &= ok(gy, vec[1]);

    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
