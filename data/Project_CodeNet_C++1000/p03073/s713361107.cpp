#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string S; cin >> S;
    int N = S.length();
    string a = "", b = "";
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) a += '1';
        else a += '0';
    }
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) b += '0';
        else b += '1';
    }
    int x = 0, y = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] != a[i]) x++;
        if (S[i] != b[i]) y++;
    }
    cout << min(x, y) << endl;
}