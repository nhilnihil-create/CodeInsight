#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;



int main(){
    ll n;
    cin >> n;
    ll a[n],b[n];
    P c[n];
    for(ll i=0;i<n;i++){
        cin >> a[i] >> b[i];
        c[i].first=a[i]+b[i];
        c[i].second=i;
    }
    sort(c,c+n,greater<P>());
    ll res=0;
    for(ll i=0;i<n;i++){
        if(i%2==0){
            res+=a[c[i].second];
        }
        else if(i%2==1){
            res-=b[c[i].second];
        }
    }
    cout << res << endl;
    return 0;
}  
