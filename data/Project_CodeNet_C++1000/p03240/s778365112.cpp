#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> coords;
    for (int i = 0; i < n; ++i) {
        int x, y, h; cin >> x >> y >> h;
        vector<int> tmp = {x, y, h};
        coords.PB(tmp);
    }
    for (int cx = 0; cx <= 100; ++cx) {
        for (int cy = 0; cy <= 100; ++cy) {
            int H;
            bool works = true;
            for (auto i : coords) {
                int x = i[0];
                int y = i[1];
                int h = i[2];
                if (h > 0) {
                    H = abs(x - cx) + abs(y - cy) + h;
                    break;
                }
            }
            for (auto i : coords) {
                int x = i[0];
                int y = i[1];
                int h = i[2];
                if (h > 0) {
                    if (H - abs(x - cx) - abs(y - cy) != h) {
                        works = false;
                        break;
                    }
                } else {
                    if (H - abs(x - cx) - abs(y - cy) > 0) {
                        works = false;
                        break;
                    }
                }
            }
            if (works) {
                cout << cx << " " << cy << " " << H << "\n";
                return 0;
            }
        }
    }
}