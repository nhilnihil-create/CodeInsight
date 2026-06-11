#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> s(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s.at(i).at(j);
        }
    }

    int cnt = 0;
    for (int b = 0; b < n; b++) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (s.at(i).at((j + b) % n) != s.at(j).at((i + b) % n)) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) cnt += n;
    }

    cout << cnt << endl;
}