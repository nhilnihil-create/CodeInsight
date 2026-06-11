#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
map<ll, pair<ll,ll> > mp;
ll dp[100000];

int main(){
    ll h,w,d;
    cin>>h>>w>>d;
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            ll a;
            cin>>a;
            mp[a]=make_pair(i,j);
        }
    }
    for(ll i=d+1;i<=h*w;i++){
        dp[i]=dp[i-d]+abs(mp[i].first-mp[i-d].first)+abs(mp[i].second-mp[i-d].second);
    }
    ll q;
    cin>>q;
    vector<ll> ans(q);
    for(ll i=0;i<q;i++){
        ll l,r;
        cin>>l>>r;
        ans[i]=dp[r]-dp[l];
    }
    for(ll i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }
}