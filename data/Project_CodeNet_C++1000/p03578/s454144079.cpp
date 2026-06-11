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

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll N;
    cin >> N;
    ll D;
    map<ll,ll> mp;
    mp.insert(make_pair(D,1));
    rep(i,N){
        cin >> D;
        if(mp.count(D)) mp[D]++;
        else mp.insert(make_pair(D,1));
    }
    ll M;
    cin >> M;
    ll T;
    string out = "YES";
    rep(i,M){
        cin >> T;
        if(mp.count(T)){
            mp[T]--;
            if(mp[T]<0){
                out = "NO";
                break;
            }
        }else{
            out = "NO";
            break;
        }
    }
    cout << out << endl;
    return 0;
}
