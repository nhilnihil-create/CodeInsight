#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> c(3,vector<int>(3));
    for (int i = 0; i <= 2; i++) {
        cin >> c.at(i).at(0);
        cin >> c.at(i).at(1);
        cin >> c.at(i).at(2);
    }

    bool can = false;
    vector<int> a(3);
    vector<int> b(3);
    for (int i1 = 0; i1 <= 100; i1++) {
        for (int i2 = 0; i2 <= 100; i2++) {
            for (int i3 = 0; i3 <= 100; i3++) {
                a.at(0) = i1;
                a.at(1) = i2;
                a.at(2) = i3;
                b.at(0) = c.at(0).at(0) - i1;
                b.at(1) = c.at(1).at(1) - i2;
                b.at(2) = c.at(2).at(2) - i3;
                if (a.at(0) + b.at(1) == c.at(0).at(1)
                && a.at(0) + b.at(2) == c.at(0).at(2) 
                && a.at(1) + b.at(0) == c.at(1).at(0)
                && a.at(1) + b.at(2) == c.at(1).at(2) 
                && a.at(2) + b.at(0) == c.at(2).at(0)
                && a.at(2) + b.at(1) == c.at(2).at(1)) {
                    can = true;
                }
                if (can) break;
            }
            if (can) break;
        }
        if (can) break;
    }

    if(can) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}