#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e10;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int X;
    cin >> X;
    int ans = 1;
    for(int i = 2; i <= X; i++) {
        int res = i;
        while (res*i <= X) {
            ans = max(ans,res*i);
            res *= i;
        }
    }
    cout << ans << endl;
}
