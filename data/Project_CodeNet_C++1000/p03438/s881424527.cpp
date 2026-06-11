#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> a(n),b(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];

    ll m = 0;

    for(ll i = 0; i < n; i++){
        if(b[i] > a[i]){
            m += (b[i]-a[i]+1)/2;
            a[i] += 2*((b[i]-a[i]+1)/2);
        }
    }

    for(ll i = 0; i < n; i++){
        if(a[i] > b[i]){
            m -= a[i]-b[i];
            b[i] = a[i];
        }
        if(m < 0){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}