#include <bits/stdc++.h>
#define INF (1e18+1)
#define LL long long
#define rep(i, c) for(int i=0;i<(int)(c);i++)
//ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n) cin >> h[i];

    sort(h.begin(), h.end());

    int ans = 1001001001;
    for(int i = 0; i+k-1 < n; i++){
        if(h[i+k-1]-h[i] < ans) ans = h[i+k-1]-h[i];
    }
    cout << ans << endl;
    return 0;

}