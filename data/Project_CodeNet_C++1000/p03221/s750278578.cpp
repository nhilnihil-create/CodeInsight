#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,m;
    cin >> n >> m;
    vector<ll>p(m),y(m);
    vector<vector<ll>>py(n+1);
    for(ll i=0;i<m;i++){
        cin >> p[i] >> y[i];
        py[p[i]].push_back(y[i]);
    }
    for(ll i=1;i<=n;i++){
        sort(py[i].begin(),py[i].end());
    }
    vector<ll>number(m);
    for(ll i=0;i<m;i++){
        auto ite=lower_bound(py[p[i]].begin(),py[p[i]].end(),y[i]);
        number[i]=ite-py[p[i]].begin()+1;
    }
    for(ll i=0;i<m;i++){
        string ans;
        ll pketa=0,pcopy=p[i];
        while(pcopy>0){
            pketa++;
            pcopy/=10;
        }
        for(ll j=0;j<6-pketa;j++){
            ans.push_back('0');
        }
        pcopy=p[i];
        for(ll j=pketa-1;j>=0;j--){
            ll x=pcopy/pow(10,j);
            x%=10;
            char pc=x+'0';
            ans.push_back(pc);
        }
        cout << endl;
        ll nketa=0,ncopy=number[i];
        while(ncopy>0){
            nketa++;
            ncopy/=10;
        }
        for(ll j=0;j<6-nketa;j++){
            ans.push_back('0');
        }
        ncopy=number[i];
        for(ll j=nketa-1;j>=0;j--){
            ll x=ncopy/pow(10,j);
            x%=10;
            char nc=x+'0';
            ans.push_back(nc);
        }
        cout << ans << endl;
    }
}
