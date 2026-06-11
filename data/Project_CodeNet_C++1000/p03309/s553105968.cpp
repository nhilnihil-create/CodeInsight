#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll ans = 0, arr[n];
    for(ll i = 1; i <= n; ++i){
        ll tmp; cin >> tmp;
        arr[i - 1] = tmp - i;
    }
    ll ans1 = 0;
    sort(arr, arr + n);
    if(n % 2){
        for(ll i = 0; i < n; ++i){
            ans += abs(arr[i] - arr[n / 2]);
        }
        cout << abs(ans);
    }else{
        for(ll i = 0; i < n; ++i){
            ans += abs(arr[i] - arr[n / 2]);
            ans1 += abs(arr[i] - arr[n / 2 - 1]);
        }
        cout << min(abs(ans), abs(ans1));
    }

    return 0;
}
