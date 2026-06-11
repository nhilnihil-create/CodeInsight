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
    vector<ll> num(k,0);
    for(ll i=1;i<=n;i++) num[i%k]++;

    ll ans = 0;
    for(ll a=0;a<k;a++){
        ll b = (k-a) % k;  //c  ==  b
        if((b*2) % k != 0) continue;  //(b+c) % k != 0
        ans += num[a] * num[b] * num[b];  //num[a] * num[b] * num[c]
    }

    cout << ans << endl;
    return 0;
}
