#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

string S;
ll K;
int main() {
    cin >> S >> K;

    // 始めが1ではない場合
    if (S[0] != '1') {
        cout << S[0] << endl;
        return 0;
    }

    // 1が何個連続するか
    ll one_num = 0;
    bool one_in = false;
    ll ans = S[0] - '0';
    rep(i, S.size()) {
        if (one_in && S[i] - '0' != 1) {
            ans = S[i] - '0';
            break;
        }
        if (S[i] - '0' == 1) {
            one_num++;
            one_in = true;
        } 
    }

    if (K <= one_num) {
        cout << 1 << endl;
    } else {
        cout << ans << endl;
    }
}