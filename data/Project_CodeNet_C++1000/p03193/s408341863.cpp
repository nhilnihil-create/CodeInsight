#include <bits/stdc++.h>

using namespace std;

#define ll long long

signed main(){
    int n; ll h,w;
    cin >> n >> h >> w;

    int ans = 0;
    for (int i = 0;i < n;++i){
        ll a,b;
        cin >> a >> b;
        if (a >= h && b >= w)
            ++ans;
    }

    cout << ans << endl;

    return 0;
}