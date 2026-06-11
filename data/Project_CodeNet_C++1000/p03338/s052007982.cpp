#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int main() {
    int N, cnt = 0; cin >> N;
    vector<char> s(N);
    for (int i = 0; i < N; i++) cin >> s.at(i);
    map<char, bool> right;
    vector<int> bucket(200, 0);
    for (int i = 0; i < N; i++) {
        bucket.at(s.at(i))++;
        if (!right.count(s.at(i))) {
            right[s.at(i)] = true;
            cnt++;
        }
    }

    int ans = 0, cnt2 = 0;
    map<char, bool> left;
    for (int i = 0; i < N; i++) {
        if (bucket.at(s.at(i)) == 1) {
            cnt--; cnt2--;
        } else bucket.at(s.at(i))--;
        if (!left.count(s.at(i))) {
            left[s.at(i)] = true;
            cnt2++;
        }
        ans = max(ans, min(cnt, cnt2));
    }
    cout << ans << endl;
}