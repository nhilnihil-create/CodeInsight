#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H, W, N;

int main() {
    cin >> H >> W >> N;
    vector<int> obst(H + 1, W + 1);   //各xにおける障害物のy座標のうち最小のもの
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        if (obst[x] > y) {
            obst[x] = y;
        }
    }
    
    int ans = H;
    int y = 1;
    for (int x = 2; x <= H; x++) {
        if (obst[x] <= y) {
            ans = x - 1;
            break;
        }
        y = (obst[x] == y + 1)? y: y + 1;
    }
    cout << ans << endl;
}