#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

int main() {
    vector<int> x(4);
    vector<int> y(4);
    for (int i = 0; i < 2; i++) {
        cin >> x.at(i) >> y.at(i);
    }
    int cx, cy, dx, dy;
    dx = (-1)*(y.at(1)-y.at(0))+x.at(0);
    dy = (x.at(1)-x.at(0))+y.at(0);
    cx = (y.at(0)-dy)*(-1)+dx;
    cy = (x.at(0)-dx)+dy;
    cout << cx << " " << cy << " " << dx << " " << dy << endl;
}