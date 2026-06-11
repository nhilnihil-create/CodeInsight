#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

// #define int ll
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define hyphen() cerr << "--\n"

#define ALL(vec) (vec).begin(), (vec).end()
#define REVALL(vec) (vec).rbegin(), (vec).rend()

#define fst first
#define pb push_back

const int MOD = (int)1e9 + 7;
const int INF = numeric_limits<int>::max();

vector<P> next_points(P p) {
    vector<P> ans(4);

    ans.at(0) = make_pair(p.first, p.second+1);
    ans.at(1) = make_pair(p.first, p.second-1);
    ans.at(2) = make_pair(p.first-1, p.second);
    ans.at(3) = make_pair(p.first+1, p.second);

    return ans;
}

bool is_valid_point(int H, int W, vector<vector<bool>> passable, P p) {
    int y = p.first;
    int x = p.second;

    return 0 <= y && y < H && 0 <= x && x < W && passable.at(y).at(x);
}


signed main() {
    int H, W;

    cin >> H >> W;

    vector<vector<bool>> passable(H, vector<bool>(W, false));
    vector<vector<int>> distance(H, vector<int>(W, -1));
    distance.at(0).at(0) = 0;

    int ok_num = 0;
    REP(i, H) {
        string s;
        cin >> s;
        REP(k, W) {
            if (s.at(k) == '.') {
                passable.at(i).at(k) = true;
                ok_num += 1;
            }
        }
    }

    // (0, 0) から (H-1, W-1)までのキョリを求める
    // そのキョリ(path)以外のマスを塗る

    queue<P> q;
    q.push(make_pair(0, 0));

    while(!q.empty()) {
        P p = q.front();
        q.pop();

        int d = distance.at(p.first).at(p.second);

        for(auto next_p : next_points(p)) {
            int next_y = next_p.first;
            int next_x = next_p.second;

            if (!is_valid_point(H, W, passable, next_p)) {
                // debug(H);
                // debug(W);
                // int f = next_p.first;
                // int s = next_p.second;
                // debug(f);
                // debug(s);
                // cout << "aaaaaa" << endl;
                continue;
            }

            // 訪れたことあるマスならスキップ
            if (distance.at(next_y).at(next_x) != -1) {
                // debug(next_y);
                // debug(next_x);
                // cout << distance.at(next_y).at(next_x) << endl;
                // hyphen();

                continue;
            }

            // debug(next_y);
            // debug(next_x);
            // hyphen();

            distance.at(next_y).at(next_x) = d + 1;
            q.push(next_p);
        }
    }

    if (distance.at(H-1).at(W-1) == -1) {
            cout << "-1" << endl;
    } else {
        int ans = ok_num - (distance.at(H-1).at(W-1) + 1);
        cout << ans << endl;
    }
}
