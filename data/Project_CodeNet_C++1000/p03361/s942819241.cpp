#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() {
    int h, w;
    cin >> h >> w;
    vector<string> vs(h, "");
    for (int i = 0; i < h; i++) {
        cin >> vs[i];
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (vs[i][j] == '.') continue;
            int flag = 0;
            if (i > 0 && vs[i - 1][j] == '#') flag = 1;
            if (j > 0 && vs[i][j - 1] == '#') flag = 1;
            if (i + 1 < h && vs[i + 1][j] == '#') flag = 1;
            if (j + 1 < w && vs[i][j + 1] == '#') flag = 1;
            if (flag == 0) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
