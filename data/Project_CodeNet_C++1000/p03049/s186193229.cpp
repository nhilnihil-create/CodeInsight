#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N;
    cin >> N;
    int last_a = 0;
    int first_b = 0;
    int both = 0;
    int res = 0;
    rep(i, N) {
        string s;
        cin >> s;
        bool judge1 = 0, judge2 = 0;
        if (s[0] == 'B')
            judge1 = 1;
        if (s[s.size() - 1] == 'A')
            judge2 = 1;
        if (judge1 && judge2)
            both++;
        if (judge1 && !judge2)
            first_b++;
        if (!judge1 && judge2)
            last_a++;
        char prev = '#';
        rep(j, s.size()) {
            if (prev == 'A' && s[j] == 'B')
                res++;
            prev = s[j];
        }
    }

    if (both >= 2) {
        res += (both - 1);
        if (first_b >= 1 && last_a >= 1) {
            first_b--, last_a--;
            res += 2;
            res += min(first_b, last_a);
        } else if (first_b == 0 && last_a != 0) {
            res += 1;
        } else if (first_b != 0 && last_a == 0) {
            res += 1;
        }

    } else if (both == 1) {
        if (first_b >= 1 && last_a >= 1) {
            first_b--, last_a--;
            res += 2;
            res += min(first_b, last_a);
        } else if (first_b == 0 && last_a != 0) {
            res += 1;
        } else if (first_b != 0 && last_a == 0) {
            res += 1;
        }
    } else {
        res += min(first_b, last_a);
    }

    cout << res << endl;
}