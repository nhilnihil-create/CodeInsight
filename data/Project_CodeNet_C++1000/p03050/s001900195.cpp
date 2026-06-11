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
string a;
vector<string> ans;
string c = "abcdefghijklm";

int main(void) {
    ll n;
    cin >> n;
    ll ans = 0;
    if(n>1){
        for(ll i = 1; i <= sqrt(n); i++){
            ll check = n-i;
            ll b = check/i;
        if(check%i==0 && n%b==i)
            ans+=check/i;
        }
    }
   // cout << 2499687339915-2499686339916 << endl;
    cout << ans << endl;
    return 0;
}
