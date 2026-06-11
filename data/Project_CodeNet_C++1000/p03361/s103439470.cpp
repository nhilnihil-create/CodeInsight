#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353
#define Graph vector<vector<int>>

int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> s(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> s.at(i).at(j);
        }
    }
    string ans = "Yes";
    bool judge;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (s.at(i).at(j) == '#') {
                judge = false;
                int ha = i - 1, hb = i + 1, wa = j - 1, wb = j + 1;
                if (ha > -1) {
                    if (s.at(ha).at(j) == '#') judge = true;
                }
                if (hb < H) {
                    if (s.at(hb).at(j) == '#') judge = true;
                }
                if (wa > -1) {
                    if (s.at(i).at(wa) == '#') judge = true;
                }
                if (wb < W) {
                    if (s.at(i).at(wb) == '#') judge = true;
                }
                if (judge == false) {
                    ans = "No";
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}