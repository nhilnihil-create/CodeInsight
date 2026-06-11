#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> z = {a, b, c};
    if (z[0] == z[1] && z[1] == z[2]) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
