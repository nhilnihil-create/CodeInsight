#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};

int main(){
    ll n,m; cin >> n >> m;
    vector<pair<ll,ll>> p;
    for(ll i = 1;i * i < m;i++){
        if(m % i == 0){
            p.push_back(make_pair(i,m / i));
        }
    }
    ll ans = 1;
    for(ll i=0;i<p.size();i++){
        if(p[i].second >= n){
            ans = max(ans,p[i].first);
        }
    }
    for(ll i=0;i<p.size();i++){
        if(p[i].first >= n){
            ans = max(ans,p[i].second);
        }
    }
    cout << ans << endl;
}