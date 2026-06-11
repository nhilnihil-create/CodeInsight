#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, y;
    cin >> n >> y;
    //get min
    if (y % 1000 != 0) {
        cout << "-1 -1 -1";
        return 0;
    }
    int nx = y / 10000;
    y = y % 10000;
    int ny = y / 5000;
    y = y % 5000;
    int nz = y / 1000;
    int diff = n - nx - ny - nz;
    if (diff < 0) {
        cout << "-1 -1 -1";
        return 0;
    } else if (diff == 0) {
        cout << nx << " " << ny << " " << nz;
        return 0;
    }
    //1 nx -> 2 ny -> 10 nz, 1 ny -> 5 nz
    while (diff > 0 && nx > 0) {
        diff--;
        ny += 2;
        nx--;
        if (diff % 4 == 0 && ny >= diff / 4) {
            //conv diff ny to nz.
            cout << nx << " " << ny - diff / 4 << " " << nz + diff / 4 * 5;
            return 0;
        }
    }
    cout << "-1 -1 -1";
}