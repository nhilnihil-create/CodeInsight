#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
    ll n;
    cin >> n;
    ll a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    ll check = min({ a,b,c,d,e });
   
    ll ans = ceil((double)n/check) + 4;
    cout << ans << endl;
    return 0;
}