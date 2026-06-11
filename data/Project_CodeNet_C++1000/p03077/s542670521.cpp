#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    ll ans=0,mini=1LL<<60,temp,n;
    cin>>n;
    rep(i,5) {
        cin>>temp;
        mini=min(mini,temp);
    }
    ans=(n+mini-1)/mini+4;
    cout<<ans<<endl;
}
