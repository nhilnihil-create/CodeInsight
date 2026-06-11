#include <iostream>
#include <iomanip>
#include <vector>

typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for(ll i=init;i<(n);i++)

int main() {
    int h, w;
    cin >> h >> w;
    char c[h][w];
    repi(i, h, 0) {
        repi(j, w, 0) {
            cin >> c[i][j];
        }
    }

    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};

    repi(i, h - 1, 1) {
        repi(j, w - 1, 1) {
            int cnt = 0;
            if (c[i][j] == '#') {
                repi(k, 4, 0) {
                    if (c[i + dy[k]][j + dx[k]] == '.')cnt++;
                }
                if (cnt == 4) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}