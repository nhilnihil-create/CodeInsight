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
    bool ok = true;
    for(ll i = 1; i <= 3500; i++){
        for(ll j = 1; j <= 3500; j++){
            ll a = n*i*j;
            ll b = 4*i*j-n*j-n*i;
        //   cout << a << " " << b << endl;
            if(b >0 && a%b==0){
                cout << i << " " << j << " " << a/b << endl;
                ok = false;
                break;
            }
        }
        if(ok==false) break;
    }
    return 0;
}
