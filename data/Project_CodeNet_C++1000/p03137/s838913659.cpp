#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i,n,init) for(ll i=init;i<(n);i++)
#define ll long long

int main()
{
    int n,m,ans;

    cin >> n >> m;
    vector<int> x(m);
    rep(i, m) {
        cin >> x[i];
    }
    //sort
    sort(x.begin(), x.end());
    //差を求める
    vector<int> sa(m - 1);
    rep(i, m - 1) {
        int t = x[i + 1] - x[i];
        sa[i] = x[i + 1] - x[i];
    }
    //sort
    sort(sa.begin(), sa.end(), greater<int>());
    //ans計算
    ans = 0;
    for (int i = n - 1;i < m-1;++i) {
        ans += sa[i];
    }

    cout << ans << endl;
    return(0);
}
