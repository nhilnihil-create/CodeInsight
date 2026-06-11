#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int f(int X) {
    int cnt = 0;
    for(int i = X/4*4; i <= X; i++) {
        cnt^=i;
    }
    return cnt;
}
signed main() {
    int A,B;
    cin >> A >> B;
    A--;
    int ans = f(A);
    ans^=f(B);
    cout << ans << endl;
}