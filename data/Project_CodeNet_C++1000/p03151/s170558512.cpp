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


int main(void){
    ll n;
    cin >> n;
    ll a[n], b[n];
    for(ll i = 0; i < n; i++)   cin >> a[i];
    for(ll i = 0; i < n; i++)   cin >> b[i];
    ll check = 0;
    vector<ll> c;
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        if(a[i]<b[i]) {
            check += abs(a[i]-b[i]);
            ans++;
        }
        else c.push_back(a[i]-b[i]);
    }
    sort(c.begin(), c.end(), greater<ll>());
    ll sum = 0;
    //cout << check << endl;
    //cout << c.size() << endl;
    if(check>0){
        for(ll i = 0; i < c.size(); i++){
            sum+=c[i];
            if(sum>=check){
                ans+=(i+1);
                break;
            }
        }
    }
    //cout << sum << " " << check << endl;
    if(sum < check) ans = -1;
    cout << ans << endl;
    return 0;
}
