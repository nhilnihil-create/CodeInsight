#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define ll long long
using namespace std;



int main() {

    int n; cin >> n;
    int ans = 1000000000;

    rep(i,n) {
        int tmp; cin >> tmp;
        int cnt = 0;

        if(tmp%2 != 0) {
            ans = 0;
            break;
        }
        while(tmp%2 == 0) {
            tmp /= 2;
            cnt++;
        }
        ans = min(ans,cnt);
    }

    cout << ans << endl;

    return 0;
}