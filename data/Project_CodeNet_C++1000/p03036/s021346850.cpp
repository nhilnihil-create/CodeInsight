#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int weight(int r, int d, int x) { return r * x - d; }

int main() {
    int r, d, x;
    cin >> r >> d >> x;

    rep(i, 10) {
        x = weight(r, d, x);
        cout << x << endl;
    }
}