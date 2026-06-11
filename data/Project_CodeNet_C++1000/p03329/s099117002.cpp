#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;
    cin >> N; 
    int ans = N;
    for(int i = 0; i <= N; i++) {
        int cnt = 0;
        int X = i; 
        int Y = N-i;
        while(X != 0) {
            cnt+=X%6;
            X/=6;
        }
        while(Y != 0) {
            cnt+=Y%9;
            Y/=9;
        }
        ans = min(ans,cnt);
    }
    cout << ans << endl;
}