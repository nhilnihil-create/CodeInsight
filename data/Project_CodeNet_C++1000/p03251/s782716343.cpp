#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int xNum, yNum, xMain, yMain;

    cin >> xNum >> yNum >> xMain >> yMain;

    vector<int> x(xNum);
    vector<int> y(yNum);

    for (int i = 0; i < xNum; i++) cin >> x.at(i);
    for (int i = 0; i < yNum; i++) cin >> y.at(i);
    sort(x.rbegin(), x.rend());
    sort(y.begin(), y.end());

    bool chk = false;
    for (int i = xMain + 1; i <= yMain; i++) {
        if (x.at(0) < i && i <=  y.at(0)) {
            chk = true;
            break;
        }
    }

    if (chk)
        cout << "No War";
    else
        cout << "War";

    //
}
