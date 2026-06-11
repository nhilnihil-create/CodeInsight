#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main(void)
{
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int ans = 0, active = 0;
    rep(i,n){
        if(active >= h[i]) active = h[i];
        else{
            ans += h[i] - active;
            active = h[i];
        }
    }
    cout << ans << endl;
    return 0;
}