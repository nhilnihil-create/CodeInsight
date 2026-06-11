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
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    if(a%2==0 && b%2!=0){
        ll c = (b-a+1)/2;
        if(c%2!=0) ans = 1;
    }
    else if(a%2==0 && b%2==0){
        ll c = (b-a)/2;
        if(c%2==0) ans = b;
        else if(c%2!=0) ans = b+1;
    }
    else if(a%2!=0 && b%2!=0){
        ll c = (b-a)/2;
        if(c%2==0) ans = a;
        else if(c%2!=0) ans = a-1;
    }
    else if(a%2!=0 && b%2==0){
        ll c = (b-a-1)/2;
        ll d = a^b;
        if(c%2!=0 && d%2==0) ans = d+1;
        if(c%2==0 && d%2==0) ans = d;
        if(c%2!=0 && d%2!=0) ans = d-1;
        if(c%2==0 && d%2!=0) ans = d;
    }
    cout << ans << endl;
    return 0;
}
