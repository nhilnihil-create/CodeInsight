#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

vector<int> op(4);
string abcd;


void solve(int depth, vector<int> &current) {

    if (depth == 3) {
        int tmp = (int) (abcd[0] - '0');

        rep(i, 3) {
            int value = (int) (abcd[i + 1] - '0');
            if (current[i] == 0) tmp -= value;
            else tmp += value;
        }
        if (tmp == 7) copy(current.begin(), current.end(), op.begin());

        return;
    }

    rep(i, 2) {
        current[depth] = i;
        solve(depth + 1, current);
    }

}

int main() {

    cin >> abcd;
    vector<int> current(4);
    solve(0, current);

    string ans;
    rep(i, 3) {
        ans += abcd[i];
        ans += op[i] ? '+' : '-';
    }
    ans += abcd[3];
    ans += "=7";

    cout << ans << endl;

    return 0;
}