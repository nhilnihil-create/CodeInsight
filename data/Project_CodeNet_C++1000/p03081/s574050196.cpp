#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, q;
string s;
vector<vector<char>> ope;

bool IsOK(bool first, int index) {
    for (int i = 0; i < q; i++) {
        if (s[index] == ope[i][0]) index += ope[i][1] == 'L' ? -1 : 1;
        if (index < 0 || n <= index)break;
    }
    if (first)return index >= 0;
    return index < n;
}

int Bin(bool first) {
    int ng = first ? -1 : n;
    int ok = first ? n : -1;

    while (abs(ok - ng) > 1) {
        int mid = ng + (ok - ng) / 2;

        if (IsOK(first, mid)) ok = mid;
        else ng = mid;
    }

    return ok;
}

int main() {
    cin >> n >> q >> s;

    ope = vector<vector<char>>(q, vector<char>(2));
    for (int i = 0; i < q; i++)cin >> ope[i][0] >> ope[i][1];

    cout << Bin(false) - Bin(true) + 1 << endl;
    return 0;
}