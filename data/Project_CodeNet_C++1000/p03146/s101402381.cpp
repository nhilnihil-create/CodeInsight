#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;
using Graph = vector<vector<ll>>;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {
    ll s;
    cin >> s;
    map<ll,ll> mp;
    ll out = 0;
    ll cnt = 0;
    ll a = 0;
    while(1){
        if(cnt==0){
            a = s;
            mp.emplace(a,1);
            cnt++;
        }
        else{
            if(a%2==1) a = 3*a+1;
            else a = a/2;
            if(mp.count(a)){
                out = cnt+1;
                break;
            }else{
                mp.emplace(a,1);
                cnt++;
            }
        }
    }
    cout << out << endl;
    return 0;
}
