#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>c(n,0),s(n,0),f(n,0);
    for(ll i=0;i<n-1;i++){
        cin >> c[i] >> s[i] >> f[i];
    }
    vector<ll>ans(n,0);
    for(ll i=0;i<n;i++){
        ll j=i+1;
        ll time=c[i]+s[i];
        while(j<n-1){
            if(time<s[j]){
                time=s[j];
            }
            if(time%f[j]!=0){
                ll dt=f[j]-(time%f[j]);
                time+=dt;
            }
            time+=c[j];
            j++;
        }
        ans[i]=time;
    }
    for(ll i=0;i<n;i++){
        cout << ans[i] << endl;
    }
}
