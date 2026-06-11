#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;

int main() {
    int A, B;
    cin >> A >> B;

    char b = '#', w = '.';
    vector<vector<char>> res(100, vector<char>(100));
    rep(i, 50) rep(j, 100) res[i][j] = b;
    for(int i=50; i<100; i++) rep(j, 100) res[i][j] = w;
    A--; B--;
    int lw = 0, lb = 51;
    while(A>0 || B>0) {
        int t = 0;
        while(t < 100) {
            if(A>0) res[lw][t] = w;
            if(B>0) res[lb][t] = b;
            t += 2;
            A--; B--;
            if(A<=0 && B<=0) break;
        }
        lw+=2;
        lb+=2;
    }

    cout << 100 << " " << 100 << endl;
    rep(i, 100) {
        rep(j, 100) {
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}