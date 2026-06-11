#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<utility>
#include<cmath>
#include<assert.h>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

int N;
int X[1010], Y[1010];
int U[1010], V[1010];//u=x+y,v=x-y
bool even;

signed main() {
    cin >> N;
    rep(i, N) {
        cin >> X[i] >> Y[i];
        if (i == 0) {
            if ((X[i] + Y[i]) % 2 == 0) {
                even = true;
            } else {
                even = false;
            }
        }
        if (even) {
            --X[i];
        }
        if ((X[i] + Y[i]) % 2 == 0) {
            cout << -1 << endl;
            return 0;
        }
        U[i] = X[i] + Y[i];
        V[i] = X[i] - Y[i];
    }
    int m;
    m = even ? 32 : 31;
    cout << m << endl;
    if (even)cout << "1 ";
    rep(i, 31) {
        cout << (i ? " " : "") << (1ll << i);
    }
    cout << endl;
    rep(i, N) {
        if (even)cout << "R";
        int u = (U[i] + (1ll << 31) - 1) / 2;
        int v = (V[i] + (1ll << 31) - 1) / 2;
        rep(j, 31) {
            if (u % 2 && v % 2)cout << "R";
            else if (u % 2 == 0 && v % 2 == 0)cout << "L";
            else if (u % 2)cout << "U";
            else cout << "D";
            u /= 2;
            v /= 2;
        }
        cout << endl;
    }
    return 0;
}
