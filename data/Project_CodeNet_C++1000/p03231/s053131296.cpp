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
    ll n, m;
    cin >> n >> m;
    string s, t;
    string cs, ct;
    cin >> s >> t;
    ll ans = n*m/__gcd(n, m);
    bool check = true;
    for(ll i = 0; i < s.length(); i+=(n/__gcd(n, m)))
        cs+=s[i];
    for(ll i = 0; i < t.length(); i+=(m/__gcd(n, m)))
        ct+=t[i];
    //cout << cs << " " << ct << endl;
    if(check==true && cs==ct)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
