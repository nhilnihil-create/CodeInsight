#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

ll cnt2(ll x){
    ll res = 0;
    while(x % 2 == 0){
        res++;
        x /= 2;
    }
    return res;
}

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n);
    ll ans = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        ans += cnt2(a[i]);
    }
    cout << ans << endl;
    return 0;
}