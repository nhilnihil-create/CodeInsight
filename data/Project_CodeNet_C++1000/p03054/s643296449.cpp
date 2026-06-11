#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int h, w, n, sr, sc;
    cin >> h >> w >> n >> sr >> sc;
    --sr;
    --sc;
    string s, t;
    cin >> s >> t;

    auto drops = [&]() {
        for (auto &setup : {
            make_tuple('R', 'L', sc, w, 1),
            make_tuple('L', 'R', sc, w, -1),
            make_tuple('D', 'U', sr, h, 1),
            make_tuple('U', 'D', sr, h, -1)
        }) {
            char dir, counterdir;
            int start, cap, dx;
            tie(dir, counterdir, start, cap, dx) = setup;
            for (int i = 0; i < n; ++i) {
                if (s[i] == dir) {
                    start += dx;
                }
                if (start < 0 || start >= cap) {
                    return false;
                }
                int undo = start;
                if (t[i] == counterdir) {
                    start -= dx;
                }
                if (start < 0 || start >= cap) {
                    start = undo;
                }
            }
        }
        return true;
    };
    cout << (drops() ? "YES" : "NO") << endl;
    return 0;
}
