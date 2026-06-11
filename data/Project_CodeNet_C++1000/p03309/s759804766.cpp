//----------------------------------------------------------------------
#include <bits/stdc++.h>
#include <numeric>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) {
        a[i] -= (i+1);
    }


    sort(a.begin(), a.end());

    int x = a[n/2];
    if(n%2==0){
        x = a[n/2-1] + a[n/2];
        x/= 2;
    }

    ll ans = 0;
    for(auto i : a) {
        ans += abs(i - x);
    }
    cout << ans << endl;
    return 0;
}
