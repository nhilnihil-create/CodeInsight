#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll>x(n);
    vector<ll>mx;
    vector<ll>px;
    for(ll i=0;i<n;i++){
        cin >> x[i];
        if(x[i]<0) mx.push_back(x[i]);
        else px.push_back(x[i]);
    }
    ll mcnt=mx.size();
    ll pcnt=px.size();
    reverse(mx.begin(),mx.end());
    ll ans=1e18;
    if(k>1){
        for(ll i=0;i<mcnt;i++){
            if(k<i-1) break;
            ll dx=0;
            dx+=(mx[i]*(-2));
            if(pcnt<k-i-1||k-i-2<0) continue;
            dx+=px[k-i-2];
            ans=min(ans,dx);
        }
        for(ll i=0;i<pcnt;i++){
            ll dx=0;
            dx+=px[i]*2;
            if(mcnt<k-i-1||k-i-2<0) continue;
            dx+=(-1)*mx[k-i-2];
            ans=min(ans,dx);
        }
    }
    if(k<=pcnt) ans=min(ans,px[k-1]);
    if(k<=mcnt) ans=min(ans,((-1)*mx[k-1]));
    cout << ans << endl;
}
