#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i < (int)n;++i)

int main() {
    int n,m;cin>>n>>m;
    pair<ll,ll>a[n];
    rep(i,n){
        cin>>a[i].first;
        cin>>a[i].second;
    }
    sort(a,a+n);
    ll ans = 0;
    ll cc = 0;
    rep(i,n){
        if(cc + a[i].second > m){
            ans+=a[i].first * (m - cc);
            break;
        }
        else {
            cc += a[i].second;
            ans += a[i].first * a[i].second;
        }
    }
    cout<<ans<<endl;
	return 0;
}