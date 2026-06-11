#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int a[3][3];
    for(int i=0; i<3; i++) for(int j=0; j<3; j++) cin >>a[i][j];

    int x[3], y[3];
    x[0] = 0;

    for(int i=0; i<3; i++) y[i] = a[0][i] - x[0];
    for(int i=0; i<3; i++) x[i] = a[i][0] - y[0];

    bool flg = true;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(x[i]+y[j] != a[i][j]) {
                flg = false;
            }
        }
    }
    if(flg) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}