#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main(){
    int n;
    cin >> n;

    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }


    ll l[n + 1], r[n + 1];
    l[0] = 0;
    for(int i = 1; i < n + 1; i++){
        l[i] = gcd(l[i - 1], a[i - 1]);
    }
    r[n] = 0;
    for(int i = n - 1; i >= 0; i--){
        r[i] = gcd(r[i + 1], a[i]);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll m = gcd(l[i], r[i + 1]);
        if(ans < m){
            ans = m;
        }
    }

    cout << ans << endl;
}