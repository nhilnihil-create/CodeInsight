#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // kondisi pertama gua perlu ceck dalam waktu t possible gak untuk trevel dari point x1,y1 ke xi, yi
    // ada urusannya dengan ganjil dan genap, . kalo distancenya ganjil time juga harus ganjil.
    // kalo distance genap time juga harus genap
    int n; cin >> n;
    int currt = 0;
    int currx = 0;
    int curry = 0;
    for (int i = 0; i < n; i++) {
        int t, x, y; cin >> t >> x >> y;
        int d = abs(currx - x) + abs(curry - y);
        int dt = abs(t - currt);
        if(d > dt || dt % 2 != d % 2) {
            cout << "No"; return 0;
        }
        currx = x; curry = y; currt = t;
    }
    cout << "Yes";
    return 0;
}
