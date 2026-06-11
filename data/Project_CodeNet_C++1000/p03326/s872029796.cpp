#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    ll x, y, z;
    vector<ll> vec[8];

    rep(i,n){
        cin >> x >> y >> z;
        vec[0].push_back(x+y+z);
        vec[1].push_back(x+y-z);
        vec[2].push_back(x-y+z);
        vec[3].push_back(x-y-z);
        vec[4].push_back(-x+y+z);
        vec[5].push_back(-x+y-z);
        vec[6].push_back(-x-y+z);
        vec[7].push_back(-x-y-z);
    }

    rep(i,8){
        sort(vec[i].begin(),vec[i].end(),greater<ll>() );
    }
    ll ans = 0;
    rep(i,8){
        ll tmp = 0;
        rep(j,m){
            tmp += vec[i][j];
        }
        ans = max(tmp,ans);
        //cout << tmp << endl;
    }

    cout << ans << endl;

    return 0;
}