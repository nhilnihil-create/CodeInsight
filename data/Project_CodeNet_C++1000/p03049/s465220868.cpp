#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 101234567;

int main() {
    int N;
    int a_cnt = 0;
    int b_cnt = 0;
    int cnt = 0;
    int ans = 0;
    string s;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s[0] == 'B') {
            b_cnt++;
        }

        if (s[s.size()-1] == 'A') {
            a_cnt++;
        }

        if (s[0] == 'B' && s[s.size()-1] == 'A') {
            cnt++;
        }

        for (int j = 1; j < s.size(); j++) {
            if (s[j-1] == 'A' && s[j] == 'B') {
                ans++;
            }
        }
    }


    b_cnt = b_cnt - cnt;
    a_cnt = a_cnt - cnt;
    if (cnt > 0) {
        ans += cnt-1;
    }

    if (cnt > 0 &&b_cnt > 0) {
        b_cnt--;
        ans++;
    }
    if (cnt > 0 && a_cnt > 0) {
        a_cnt--;
        ans++;
    }

    ans += min(b_cnt, a_cnt);

    cout << ans << endl;
}
