#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;



int main(){
    ll n;
    ll res=0;
    cin >> n;
    ll a[n];
    ll totala=0;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        totala+=a[i];
    }
    ll b[n];
    ll c[n];
    ll totalb=0;
    ll count=0;
    for(ll i=0;i<n;i++){
        cin >> b[i];
        totalb+=b[i];
        c[i]=a[i]-b[i];
        if(a[i]-b[i]<0){
            res++;
            count+=abs(a[i]-b[i]);
        }
    }
    if(totala<totalb){
        cout << -1 << endl;
        return 0;
    }
    sort(c,c+n);
    ll memo=n-1;
    while(1){
        if(count<=0) break;
        count-=c[memo];
        res++;
        memo--;
    }
    cout << res << endl;
    return 0;
}  
