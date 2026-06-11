#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i,n,init) for(ll i=init;i<(n);i++)
#define ll long long

int main()
{
    int n,k,ans;

    cin >> n >> k;
    vector<int> h(n);
    rep(i, n) {
        cin >> h[i];
    }
    //sort
    sort(h.begin(), h.end());

    ans = INT_MAX;
    for (int i = 0;i <= n - k;++i) {
        int sa = h[i + k - 1] - h[i];
        ans = min(ans, sa);
    }

    cout << ans << endl;
    return(0);
}
