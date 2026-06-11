#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    ll n,z,w;
    cin >>n >>z >>w;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    if(n==1){
        cout<<abs(a[0]-w)<<endl;
        return 0;
    }
    ll all = (ll)abs(w-a[n-1]);
    ll ans = (ll)abs(a[n-2]-a[n-1]);
    cout<<max(all,ans)<<endl;
    return 0;    

    

}