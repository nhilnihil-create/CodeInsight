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
ll n;
ll ans = 0;
void func(ll a){
    string s = to_string(a);
    vector<bool> ok(3, false);
    for(ll i = 0; i < s.length(); i++){
        if(s[i]=='3') ok[0] = true;
        if(s[i]=='5') ok[1] = true;
        if(s[i]=='7') ok[2] = true;
    }
    if(ok[0]&&ok[1]&&ok[2]&&a<=n) {
        ans++;
     //   cout << a << endl;
    }
    if(a<n){
        func(a*10+3); func(a*10+5); func(a*10+7);
    }
}
int main(void) {
    cin >> n;
    func(3);
    func(5);
    func(7);
    cout << ans << endl;
    return 0;
}
