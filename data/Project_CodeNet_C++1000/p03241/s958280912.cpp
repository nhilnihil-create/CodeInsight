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
    ll n, m;
    cin >> n >> m;
    vector<ll> a;
    for(ll i = 1; i <= sqrt(m); i++){
        if(m%i==0) {
            a.push_back(i);
            a.push_back(m/i);
        }
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for(ll i = 0; i < a.size(); i++){
        if(m/a[i]>=n) ans = a[i];
    }
    cout << ans << endl;
    return 0;
}
