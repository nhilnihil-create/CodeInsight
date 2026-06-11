#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main() {
    int n,k;
    cin >> n >> k;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];

    sort(h.begin(),h.end());
    ll ans=h.at(n-1);

    rep(i,n-k+1){
        // if(ans>x) ans=x;
        ans=min(h[i+k-1]-h[i],ans);
    }

    cout << ans << endl;
}