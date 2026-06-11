#include <bits/stdc++.h>
using namespace std;
#define vec(type) vector<type>

int main() {
    int p[3][2];
    cin >>  p[0][0] >> p[0][1] >>
            p[1][0] >> p[1][1] >>
            p[2][0] >> p[2][1];

    int c[4] = {0,0,0,0};
    for (int i = 0; i < 3; i++) {
        c[p[i][0]-1]++;
        c[p[i][1]-1]++;
    }

    int n[4] = {0,0,0,0};
    for (int i = 0; i < 4; i++) {
        n[c[i]]++;
    }

    if (n[1]==2 && n[2]==2) cout << "YES" << endl;
    else cout << "NO" << endl;
}