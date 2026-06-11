#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using ll = long long;
using ld = long double;
using namespace std;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main(){
    FIN;
    ll n,k; cin >> n >> k;
    map<ll,ll> a;
    ll s = 0; //種類

    for(int i=0;i<n;i++){
        ll num; cin >> num;
        a[num]++;
        if(a[num] == 1) s++;
    }

    if(s <= k){ cout << 0 << endl; return 0;}

    priority_queue<ll,vector<ll>,greater<ll>> que;
    map<ll,ll>::iterator it;
    for(it=a.begin();it!=a.end();it++)
        que.push(it->second);

    ll ans = 0;
    for(int i=0;i<s-k;i++){
        ans += que.top();
        que.pop();
    }

    cout << ans << endl;
    return 0;
}

