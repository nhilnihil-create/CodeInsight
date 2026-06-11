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
    ll N,M;
    cin >> N >> M;
    vector<pair<pair<ll,ll>,ll>> v(M);
    rep(i,M){
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
    sort(v.begin(),v.end());
    vector<pair<ll,ll>> out(M);
    ll cnt = 1;
    rep(i,M){
        out[v[i].second].first = v[i].first.first;
        if(i==0) ;
        else if(v[i].first.first==v[i-1].first.first) cnt++;
        else cnt = 1;
        out[v[i].second].second = cnt;
    }
    rep(i,M) cout << setfill('0') << right << setw(6) << out[i].first << setfill('0') << right << setw(6) << out[i].second << endl;
    return 0;
}
