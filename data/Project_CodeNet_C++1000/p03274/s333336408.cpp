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
    ll n, k;
    cin >> n >> k;
    vector<ll> p, m;
    p.push_back(0); m.push_back(0);
    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        if(a>0) p.push_back(a);
        else m.push_back(-1*a);
    }
    sort(m.begin(), m.end());
    ll ans = 0;
    if(p.size()==1) ans = m[k];
    else if(m.size()==1) ans = p[k];
    else {
        ans = 1e+15;
        for(ll i = 1; i < p.size(); i++){
            if(i==k) break;
            if(k-i>=m.size()) continue;
            ans = min(ans, p[i]*2+m[k-i]);
          //  cout << i << " " << k-i << " " << ans << endl;
        }
        for(ll i = 1; i < m.size(); i++){
            if(i==k) break;
            if(k-i>=p.size()) continue;
            ans = min(ans, m[i]*2+p[k-i]);
            //cout << ans << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
