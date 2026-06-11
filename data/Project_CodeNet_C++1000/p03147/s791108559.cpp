#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(void)
{
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int ans = h[0];
    rep(i,n-1) ans += max(0, h[i+1]-h[i]);
    cout << ans << endl;
    return 0;
}