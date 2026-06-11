#include <bits/stdc++.h>
using namespace std;
#define int long long
int INF = 1e9;
signed main() {
	int N;
    cin >> N;
    int ans = INF;
    for(int i = 1; i < N; i++) {
        int X = i;
        int Y = N-i;
        int cnt = 0;
        while(X != 0) {
            cnt+=X%10;
            X/=10;
        }
        while(Y != 0) {
            cnt+=Y%10;
            Y/=10;
        }
        ans = min(ans,cnt);
    }
    cout << ans << endl;
}