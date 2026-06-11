#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;



int main(){
    ll n;
    cin >> n;
    ll res=0;
    for(ll i=1;i*i<n;i++){
        ll ans=(n-i)/i;
        if((n-i)%i==0&&ans>i) res+=ans;
    }
    cout << res << endl;
    return 0;
}  
