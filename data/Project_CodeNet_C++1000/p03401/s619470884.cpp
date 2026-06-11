#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#define ll long long
using namespace std;

int main(void){
    ll n;
    cin >> n;
    vector<ll> a;
    a.push_back(0);
    for(ll i = 0; i < n; i++){
        ll count;
        cin >> count;
        a.push_back(count);
    }
    a.push_back(0);
    ll ans = 0;
    for(ll i = 1; i < a.size(); i++)
        ans += abs(a[i]-a[i-1]);
    for(ll i = 1; i < a.size()-1; i++){
        if(a[i-1] < a[i] && a[i] > a[i+1])
            cout << ans - abs(a[i]-a[i-1]) - abs(a[i]-a[i+1]) + abs(a[i+1]-a[i-1]) << endl;
        else if(a[i-1] > a[i] && a[i] < a[i+1])
            cout << ans -abs(a[i]-a[i-1]) - abs(a[i]-a[i+1])+ abs(a[i+1]-a[i-1]) << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
