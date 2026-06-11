#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;
vector<ll> a;

main(){
    cin >> n;
    a.resize(n);
    for(int i=0;i<n;++i){
        cin >> a[i];
    }

    ll ans = 0;

    ll i =0;
    ll j = 0;
    ll teks = 0;
    ll tekx = 0;
    while(i<n){
        while(j<n && teks+a[j] == (tekx^a[j]) ){
            teks+=a[j];
            tekx^=a[j];
            j++;
        }
        ans += j-i;
        teks -= a[i];
        tekx = (tekx^a[i]);
        i++;
        j = max(j,i);
    }
    cout << ans;

}
