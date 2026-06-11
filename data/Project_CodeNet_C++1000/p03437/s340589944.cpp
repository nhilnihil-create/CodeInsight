#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int X,Y;
    cin >> X >> Y;
    if(X%Y == 0) {
        cout << -1 << endl;
    }
    else {
        cout << X << endl;
    }
}
