#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> c(3, vector<int>(3, 0));

    for(auto &row: c) {
        for(auto &x: row) {
            cin >> x;
        }
    }
    vector<int> a(3, 0);
    a[0] = c[0][0];
    a[1] = c[1][0];
    a[2] = c[2][0];

    bool isCreate = false;
    // 差が等しければb2を足すことで[c12, c22, c32]^T を生成できる
    if ((c[0][1] - a[0] == c[1][1] - a[1]) && (c[1][1] - a[1] == c[2][1] - a[2])) {
        isCreate = true;
    }
    if (!isCreate) {
        cout << "No" << endl;
        return 0;
    }
    
    isCreate = false;
    // 差が等しければb3を足すことで[c13, c23, c33]^T を生成できる
    if ((c[0][2] - a[0] == c[1][2] - a[1]) && (c[1][2] - a[1] == c[2][2] - a[2])) {
        isCreate = true;
    }
    if (!isCreate) {
        cout << "No" << endl;
        return 0;
    }
    
    cout << "Yes" << endl;
}
