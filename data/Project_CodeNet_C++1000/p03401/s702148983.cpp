#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ll n; cin >> n;
    ll arr[n + 2] = {0};
    ll cnt = 0;
    for(ll i = 1; i < n + 1; ++i){
        cin >> arr[i];
    }
    for(ll i = 1; i < n + 1; ++i){
        cnt += abs(arr[i] - arr[i - 1]);
    }
    cnt += abs(arr[n] - arr[0]);
    for(ll i = 1; i < n + 1; ++i){
        cout << cnt - abs(arr[i + 1] - arr[i]) - abs(arr[i] - arr[i - 1]) + abs(arr[i + 1] - arr[i - 1])<< endl;
    }
    return 0;
}
