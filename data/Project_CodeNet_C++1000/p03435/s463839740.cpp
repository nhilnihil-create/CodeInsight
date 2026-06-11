#include <bits/stdc++.h>
using namespace std;


void solve() {
    int v[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
        }
    }
    for (int a = 0; a <= v[0][0]; a++) {
        int b = v[0][0] - a;
        bool ok = 1;
        for (int i = 1; i < 3&&ok; i++) {
            for (int j = 1; j < 3&&ok; j++) {
                int aij = v[i][0] - b;
                int bij = v[0][j] - a;
                if(aij + bij != v[i][j]) {
                    ok = 0;
                }
            }
        }
        if(ok) {
            cout << "Yes";
            return;
        }
    }
    cout << "No";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
