#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n + 2,0);
    vector<ll> sum;
    int l = 0;
    ll ans = 0;
    for(int i = 1; i < n + 1; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n + 2; i++){
        ans += abs(a[i] - a[i - 1]);
    }
    for(int i = 1; i < n + 1; i++){
        cout << ans + abs(a[i - 1] - a[i + 1]) - (abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1])) << endl;
    }
}