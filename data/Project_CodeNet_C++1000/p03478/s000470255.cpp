#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0 ; i < (int)(n) ; i++)
typedef long long ll;
////////////////////////////////////////////////
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    rep(i,n+1){
        int cnt = 0, k = i;
        rep(j,5){
            cnt += (k % 10);
            k /= 10;
        }
        if (a <= cnt && cnt <= b) ans += i;
    }
    cout << ans << endl;
}