#include<iostream>
#include<algorithm>
#include<vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    vector<int> a(n),b(n),c(n);
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    rep(i,n) cin>>c[i];
    sort(a.begin(),a.end());
    sort(c.begin(),c.end());

    ll ans =0;
    rep(j,n){
        ll numa = lower_bound(a.begin(),a.end(),b[j]) - a.begin();
        ll numc = c.end() - upper_bound(c.begin(),c.end(),b[j]);
        ans += numa * numc;
    }
    cout<<ans<<endl;

    return 0;
}