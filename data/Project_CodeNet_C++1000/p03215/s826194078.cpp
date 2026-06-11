#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout << fixed << setprecision(33);

    
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> v;
    for(int i=0;i<n;i++){
        ll sum = 0;
        for(int j=i;j<n;j++){
            sum += a[j];
            v.push_back(sum);
        }
    }

    ll ans = 0;

    for(ll i=44;i>=0;i--){
        vector<ll> ret;
        for(auto j:v){
            if((j&(1LL<<i))){
                ret.push_back(j);
            }
        }
        if(ret.size()>=k){
            v = ret;
            ans += (1LL<<i);
        }
    }
    cout << ans << endl;
}