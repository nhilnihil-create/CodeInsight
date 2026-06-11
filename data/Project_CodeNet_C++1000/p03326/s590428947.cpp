#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    std::vector<long> pn[8];
    for (int i = 0; i < n; i++) {
        long x, y, z;
        cin >> x >> y >> z;
        pn[0].push_back(+x +y +z);
        pn[1].push_back(+x +y -z);
        pn[2].push_back(+x -y +z);
        pn[3].push_back(-x +y +z);
        pn[4].push_back(-x -y +z);
        pn[5].push_back(-x +y -z);
        pn[6].push_back(+x -y -z);
        pn[7].push_back(-x -y -z);

    }
    long res = 0;
    for (int i = 0; i < 8; i++) {
        sort(pn[i].begin(), pn[i].end(), greater<>());
        long tres = accumulate(pn[i].begin(), pn[i].begin() + m, 0l);
        if (tres > res) {
            res = tres;
        }
    }
    cout << res << endl;
}
