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

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll N,M;
    cin >> N >> M;
    vector<ll> v;
    rep(i,sqrt(M)){
        if(M%(i+1)==0){
            v.push_back(i+1);
            v.push_back(M/(i+1));
        }
    }
    sort(v.begin(),v.end());
    ll out = 0;
    rep(i,v.size()){
        if(N<=v[i]){
            out = M/v[i];
            break;
        }
    }
    cout << out << endl;
    return 0;
}
