#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin >>n;
    vector<ll> a(n), b(n);
    ll suma=0, sumb=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        suma += a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
        sumb += b[i];
    }
    if(suma<sumb) cout << -1 << endl;
    else{
        vector<ll> diff(n);
        int ans=0;
        ll lack=0;
        for(int i=0; i<n; i++){
            diff[i]=a[i]-b[i];
        }
        sort(diff.begin(), diff.end());
        int i = 0;
        while(diff[i]<0){
            lack += diff[i];
            i ++;
        }
        ans += i;
        int j=0;
        while(lack<0){
            lack += diff[n-1-j];
            j++;
        }
        ans += j;
        cout << ans << endl;
    }
}