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
    map<ll,ll> mp;
    vector<ll> v;
    rep(i,N){
        ll a;
        cin >> a;
        if(mp.count(a)) mp[a]++;
        else{
            mp.emplace(a,1);
            v.push_back(a);
        }
    }
    ll M = v.size();
    ll out = 0;
    rep(i,M){
        if(mp[v[i]]>=v[i]) out += mp[v[i]]-v[i];
        else out += mp[v[i]];
    }
    cout << out << endl;
    return 0;
}
