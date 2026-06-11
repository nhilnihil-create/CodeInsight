#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<char>> data(2, vector<char>(3));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> data.at(i).at(j);
        }
    }

    if (data[0][0] == data[1][2] && data[0][1] == data[1][1] && data[1][0] == data[0][2]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}