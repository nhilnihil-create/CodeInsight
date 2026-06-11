#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll a[55];

int main(){
    cin >> n;
    ll mmax=0,mmin=0;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        if(a[i]>a[mmax]) mmax=i;
        if(a[i]<a[mmin]) mmin=i;
    }
    if(abs(a[mmax])>=abs(a[mmin])){
        cout << 2*n-1 << endl;
        for(ll i=0;i<n;i++){
            cout << mmax+1 << " " << i+1 << endl;
        }
        for(ll i=0;i<n-1;i++){
            cout << i+1 << " " << i+2 << endl;
        }
    }
    else{
        cout << 2*n-1 << endl;
        for(ll i=0;i<n;i++){
            cout << mmin+1 << " " << i+1 << endl;
        }
        for(ll i=0;i<n-1;i++){
            cout << n-i << " " << n-i-1 << endl;
        }
    }
}
