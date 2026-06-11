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

ll gcd(ll a, ll b){
   if (a%b == 0)  return(b);
   else  return(gcd(b, a%b));
}

ll lcm(ll a, ll b){
   return a * b / gcd(a, b);
}


int main(){
    FIN;
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n);
    cin >> a[0];
    ll ans = abs(x - a[0]);

    if(n == 1){
        cout << ans << endl;
        return 0;
    }

    for(ll i=1;i<n;i++){
        cin >> a[i];
        ans = gcd(ans,abs(a[i]-x));
    }

    cout << ans << endl;
    return 0;
}
