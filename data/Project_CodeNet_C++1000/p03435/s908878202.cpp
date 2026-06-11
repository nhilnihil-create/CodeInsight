#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    vector<vector<int> > v(3, vector<int>(3));
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cin >> v[i][j];

    vector<int> a(3), b(3);
    for (int i = 0; i <= 100; i++) {
        a[0] = i;
        b[0] = v[0][0] - a[0];
        for (int j = 1; j <= 2; j++) {
            a[j] = a[0] - (v[0][0] - v[j][0]);
            b[j] = b[0] - (v[0][0] - v[0][j]);
        }
        bool can = true;
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
            if (v[i][j] != a[i] + b[j]) can = false;
        if (can) {
            cout << "Yes" << '\n';
            return 0;
        }
    }

    cout << "No" << '\n';
}
