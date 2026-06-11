#include <iostream>
#include <vector>
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define all(x) (x).begin(),(x).end()
#define dump(x) cout << #x << " = " << (x) << endl

using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;
vector<int> di = {1, 0};
vector<int> dj = {0, 1};


int main() {
    int h, w; cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w, 0));
    rep(i, h)rep(j, w) cin >> a[i][j];

    int cnt = 0;
    vector<P> mae, ato;
    rep(i, h) rep(j, w) {
        rep(dir, 2) {
            if (a[i][j] % 2 == 0) continue;
            int ni = i + di[dir], nj = j + dj[dir];

            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            cnt++;
            a[i][j]--;
            a[ni][nj]++;
            mae.emplace_back(i, j);
            ato.emplace_back(ni, nj);
            break;
        }
    }
    cout << cnt << endl;
    rep(i, mae.size()) {
        cout << mae[i].first + 1 << " " << mae[i].second + 1 << " " << ato[i].first + 1 << " " << ato[i].second + 1 << endl;
    }
}