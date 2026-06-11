#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int c[3][3];
    rep(i, 3){
        rep(j, 3){
            cin >> c[i][j];
        }
    }
    bool ok = true;
    int b0 = c[0][0]*2 - c[0][1] - c[0][2];
    int b1 = c[1][0]*2 - c[1][1] - c[1][2];
    int b2 = c[2][0]*2 - c[2][1] - c[2][2];

    int a0 = c[0][0]*2 - c[1][0] - c[2][0];
    int a1 = c[0][1]*2 - c[1][1] - c[2][1];
    int a2 = c[0][2]*2 - c[1][2] - c[2][2];

    if(b0 != b1 || b1 != b2 || b2 != b0 || a0 != a1 || a1 != a2 || a2 != a0){
        ok = false;
    }

    if(ok){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}