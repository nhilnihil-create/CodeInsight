#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int X, Y; cin >> X >> Y;
    vector<int> x(n);
    for (auto &xi: x) cin >> xi;
    x.emplace_back(X);
    vector<int> y(m);
    for (auto &yi: y) cin >> yi;
    y.emplace_back(Y);
    int ma_x = *max_element(begin(x), end(x));
    int mi_y = *min_element(begin(y), end(y));
    cout << (ma_x < mi_y ? "No War" : "War") << endl;
    return 0;
}
