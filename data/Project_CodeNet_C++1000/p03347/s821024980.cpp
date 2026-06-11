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
    ll a[n];
    bool ok = true;
    ll MAX = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        if(i!=0 && a[i]-a[i-1]>=2)
            ok = false;
        MAX = max(MAX, a[i]);
    }
    if(a[0]!=0) ok = false;
    if(ok==false)
        cout << -1 << endl;
    else if(ok==true){
        ll ans = 0;
        for(ll i = 1; i < n; i++){
            if(a[i]>a[i-1]) ans++;
            else if(a[i]==a[i-1]) ans+=a[i];
            else if(a[i]!=0) ans+= a[i];
           // cout << i << " " << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
