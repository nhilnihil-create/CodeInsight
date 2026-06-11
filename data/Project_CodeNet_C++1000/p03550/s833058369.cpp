#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
const ll MOD=1000000007;

int main(){
    int N;
    ll Z,W;
    cin >> N >> Z >> W;
    vector<ll> a(N);
    rep (i,N){
        cin >> a[i];
    }
    int ans;
    if (N>1){
        ans=max(abs(a[N-1]-W),abs(a[N-1]-a[N-2]));
    }
    else {
        ans=abs(a[0]-W);
    }
    cout << ans << endl;
}