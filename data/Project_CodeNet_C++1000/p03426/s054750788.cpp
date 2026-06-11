#include <iostream>
#include <vector>
#include <array>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int h, w, d;
    cin >> h >> w >> d;

    int a;
    vector<array<int, 2>> xy(h * w + 1);
    rep(i, h) {
        rep(j, w) {
            cin >> a;
            xy[a] = {i, j};
        }
    } 

    vector<long> memo(h * w + 1);
    int j;
    rep(i, h * w) {
        j = i + 1;
        if(j <= d) {
            memo[j] = 0;
        } else {
            memo[j] = memo[j-d] + abs(xy[j][0] - xy[j-d][0]) + abs(xy[j][1] - xy[j-d][1]);
        }
    }

    int q, l, r;
    cin >> q;

    rep(i, q) {
        cin >> l >> r;
        cout << memo[r] - memo[l] << endl;
    }
}