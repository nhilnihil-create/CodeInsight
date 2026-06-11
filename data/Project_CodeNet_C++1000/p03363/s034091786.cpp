#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#include <numeric>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[8]={ 0, 1, 0,-1, 1, 1,-1,-1}; // x軸方向への変位
ll dy[8]={ 1, 0,-1, 0, 1,-1, 1,-1}; // y軸方向への変位

int main(void) {
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++)
        cin >> a[i];
    ll sum[n];
    sum[0] = a[0];
    for(ll i = 1; i < n; i++){
        sum[i] = sum[i-1]+a[i];
    }
    map<ll, ll> I{};
    ll ans = 0;
    for(ll i = 0; i < n; i++) I[sum[i]]++;
    for(auto x : I){
        //cout << x.first << " " << x.second << endl;
        if(x.first==0) ans+=x.second;
        ans += (x.second)*(x.second-1)/2;
    }
    cout << ans << endl;
    return 0;
}
