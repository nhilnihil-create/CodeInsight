#define loop(i, s, e) for(ll i = s;i < e;i++)

#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <map>
#include <cmath>
//#include "vector2d.cpp"

using namespace std;
//using namespace libcgl;
typedef long long signed ll;

ll n,a[100000];

pair<ll,ll> extgcd(ll a,ll b) {
    if(b == 0) return make_pair(1,0);
    ll c = a % b;
    ll s = a / b;
    auto g = extgcd(b,c);
    return make_pair(g.second,g.first - s * g.second);
}

ll invmod(ll mod,ll n) {
    auto g = extgcd(mod,n);
    return g.second;
}

int main() {
    cin >> n;
    loop(i,0,n) cin >> a[i];
    sort(a,a+n);
    auto l = lower_bound(a,a+(n-1),a[n-1]/2);
    if(*l == a[n-1]) cout << a[n-1] << " " << *(l-1);
    else if(*l == a[0]) cout << a[n-1] << " " << a[0];
    else if(abs((double)*l - ((double)a[n-1] / 2)) > abs((double)*(l-1) - ((double)a[n-1] / 2)) )
        cout << a[n-1] << " " << *(l-1);
    else cout << a[n-1] << " " << *l;
}

