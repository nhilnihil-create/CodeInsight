#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <utility>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

bool comp(const pii &a, const pii &b){
    if(a.first < b.first) return true;   
    return false;
}

int main(){
    ll n,m;
    cin >> n >> m;
    vector<pii> vec(n);
    ll a,b;
    rep(i,n){
        cin >> a >> b;
        vec[i] = make_pair(a,b);
    }

    sort(vec.begin(), vec.end(), comp );
    ll ans = 0;

    rep(i,n){
        ans += min(vec[i].second, m)*vec[i].first;
        m -= vec[i].second;
        if(m < 0)break;
    }
    cout << ans << endl;

    return 0;
}