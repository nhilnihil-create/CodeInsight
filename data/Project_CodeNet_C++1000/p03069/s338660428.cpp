#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};

int main(void){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll w[n], b[n];
    w[0] = 0; b[0] = 0;
    if(s[0]=='.') w[0]++;
    else b[0]++;
    for(ll i = 1; i < n; i++){
        if(s[i]=='.'){
            w[i] = w[i-1]+1;
            b[i] = b[i-1];
        }
        else if(s[i]=='#'){
            b[i] = b[i-1]+1;
            w[i] = w[i-1];
        }
    }
    ll mw = w[n-1], mb = b[n-1];
    ll MIN = min(mw, mb);
    ll ans = 1e+11;
    for(ll i = 0; i < n; i++){
        ll check = min(mw-w[i]+b[i], mw);
        ans = min(ans, check);
        ans = min(ans, MIN);
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
