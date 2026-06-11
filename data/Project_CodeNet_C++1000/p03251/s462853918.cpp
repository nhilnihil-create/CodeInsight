#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n, m, X, Y;
    int x[110], y[110];

    cin >> n >> m >> X >> Y;
    int max_x = X, min_y = Y;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        max_x = max(max_x, x[i]);
    }

    for (int i = 0; i < m; i++) {
        cin >> y[i];
        min_y = min(min_y, y[i]);
    }

    if (min_y > max_x) cout << "No War" << endl;
    else cout << "War" << endl;
}