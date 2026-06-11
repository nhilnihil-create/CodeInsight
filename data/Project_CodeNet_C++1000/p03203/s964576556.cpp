#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(long long)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

vector<int> p[200001];

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    rep(i, N) {
        int r, c;
        cin >> r >> c;
        p[r].push_back(c);
    }
    rep(i, H) sort(p[i].begin(), p[i].end());

    int len = 1;
    for (int i=1; i<=H-1; ++i) {
        //cout << "len = " << len << endl;
        for (int j=0; j<p[i+1].size(); ++j) {
            if (len >= p[i+1][j]) {
                cout << i << endl;
                return 0;
            }
        }
        if (len < W) {
            bool ok = true;
            for (int j=0; j<p[i+1].size(); ++j) {
                if (len+1 == p[i+1][j]) {
                    ok = false;
                    break;
                }
                else if (len+1 < p[i+1][j]) break;
            }
            if (ok) len++;
        }
    }
    cout << H << endl;
    return 0;
}
