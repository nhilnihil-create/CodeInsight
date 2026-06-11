#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int ans = 20000;
    for (int i = 0; i < S.size() - 2; i++) {
        int x = stoi(S.substr(i, 3));
        if (abs(753 - x) < abs(753 - ans)) {
            ans = x;
        }
    }
    cout << abs(753 - ans) << endl;
    return 0;
}
