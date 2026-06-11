#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long INF = 1LL << 60;
using Graph = vector<vector<int>>;

const int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
const int dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

inline int gcd(int a, int b) { return (a%b == 0) ? b : gcd(b, a%b); }
inline int fac(int n) { return (n==0) ? 1 : n * fac(n - 1); }

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }

    for (int iy = 0; iy < h; iy++) {
        for (int ix = 0; ix < w; ix++) {
            if (s[iy][ix] == '#')
                continue;
            int cnt = 0;
            for (int m = 0; m < 8; m++)
            {
                int x = ix + dx[m];
                int y = iy + dy[m];
                if (0 <= x && x < w && 0 <= y && y < h) {
                    if (s[y][x] == '#') {
                        cnt++;
                    }
                }
            }
            s[iy][ix] = cnt + '0';
        }
    }

    for (int iy = 0; iy < h; iy++) {
        cout << s[iy] << endl;
    }
    return 0;
}
