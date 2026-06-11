#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long INF = 1LL << 60;
using Graph = vector<vector<int>>;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

inline int gcd(int a, int b) { if (a%b == 0) { return b; } else { return gcd(b, a%b); } }

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }

    for (int iy = 0; iy < h; iy++) {
        for (int ix = 0; ix < w; ix++) {
            if (s[iy][ix] == '.') {
                continue;
            }
            bool okay = false;
            for (int k = 0; k < 4; k++) {
                int y = iy + dy[k];
                int x = ix + dx[k];
                if (0 <= x && 0 <= y && x < w && y < h && s[y][x] == '#')
                {
                    okay = true;
                    break;
                }
            }
            if (okay == false) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}