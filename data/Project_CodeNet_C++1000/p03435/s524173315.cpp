#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int a[3][3];
int x[3];
int y[3];

int main(){
    rep(i, 3) {
        rep(j, 3) cin >> a[i][j];
    }
    x[0] = 0;
    rep(i, 3) y[i] = a[0][i] - x[0];
    rep(i, 3) x[i] = a[i][0] - y[0];

    bool good = true;
    rep(i, 3) {
        rep(j, 3) {
            if(x[i]+y[j] != a[i][j]) {
                good = false;
            }
        }
    }

    if(good) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}