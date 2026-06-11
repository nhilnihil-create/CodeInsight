#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

int main(){
    int n;
    cin >> n;
    vl s(n+1,0);
    ll tmp;
    map<ll,ll> mp;
    rep(i,n){
        cin >> tmp;
        s[i+1] = s[i] + tmp;
    }

    reps(i,1,n+1){
        mp[s[i]]++;
    }
    ll ans = 0;
    for(auto e: mp){
        if(e.first == 0) ans += e.second;
        if(e.second > 1)ans += (e.second)*(e.second-1)/2;
        //cout << e.first << " " << e.second << endl;
    }

    cout << ans << endl;
    return 0;
}