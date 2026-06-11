#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    ll X, Y; cin >> X >> Y;
    ll ans = 1;
    while(X <= Y){
        X *= 2;
        if(X <= Y){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}