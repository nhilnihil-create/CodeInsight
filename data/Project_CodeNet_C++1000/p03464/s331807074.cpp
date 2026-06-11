#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    
    ll n;
    cin>>n;
    ll a[n];
    ll mx = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx = max(mx,a[i]);
    }
    ll ans1 = -1;
    long long low=-1,up=1e15+7,mid;
    while(up-low>1){
        mid=(up+low)/2;
        ll k = mid;
        for(int i=0;i<n;i++){
            k -= k%a[i];
        }
        if(k<=1){
            low=mid;
        }
        else{
            up=mid;
        }
    }
    ans1 = up;
    low=-1,up=1e15+7;
    while(up-low>1){
        mid=(up+low)/2;
        ll k = mid;
        for(int i=0;i<n;i++){
            k -= k%a[i];
        }
        if(k<=2){
            low=mid;
        }
        else{
            up=mid;
        }
    }
    ll ans2 = low;
    if(ans1>ans2){
        cout << -1 << endl;
        return 0;
    }
    cout << ans1 << " " << ans2<< endl;
    
}