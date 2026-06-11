#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    ll cnt =0;
    for(ll i=0;i<n;i++){
        while(a[i]%2==0){
            cnt++;
            a[i]/=2;
        }
    }
    cout << cnt << endl;
}