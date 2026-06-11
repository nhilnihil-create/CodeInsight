#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

vector<int> distX = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<int> distY = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) {
        cin >> S.at(i);
    }

    rep(i, H) {
        rep(j, W) {
            if (S.at(i).at(j) == '#') continue;
            // 周りに何個「#」があるか調べる
            int count = 0;
            rep(k, 8) {
                int aroundY = i + distY.at(k);
                int aroundX = j + distX.at(k);
                if (aroundX < 0 || W - 1 < aroundX) continue;
                if (aroundY < 0 || H - 1 < aroundY) continue;
                if (S.at(aroundY).at(aroundX) == '#') count++;
            }
            S.at(i).at(j) = (char)('0' + count);
        }
    }

    rep(i, H) {
        cout << S.at(i) << endl;
    }

    return 0;
}