#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> v(h + 1, w);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x - 1] = min(v[x - 1], y - 1);
    }
    v[h] = -1;

    int nowy = 0;
    for (int i = 0; i <= h; i++) {
        if (v[i] < nowy) {
            cout << i << endl;
            break;
        }
        if (v[i] != nowy)nowy++;
    }
    return 0;
}