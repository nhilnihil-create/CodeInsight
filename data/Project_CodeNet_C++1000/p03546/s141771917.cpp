#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int d[10][10] = {};
void warshall_floyd(int n) {
    for (int k = 0; k < n; k++){       // 経由する頂点
        for (int i = 0; i < n; i++) {    // 始点
            for (int j = 0; j < n; j++) {  // 終点
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    int h, w;
    cin >> h >> w;
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            cin >> d[j][i];
        }
    }
    warshall_floyd(10);
    long long sum = 0;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            int x;
            cin >> x;
            if(x == -1)continue;
            sum += d[1][x];
        }
    }
    cout << sum<< endl;
}
