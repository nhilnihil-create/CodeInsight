#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for (ll i = 0; i < (n); ++i)


int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll maxv = min(a, b);
    ll minv = max(a + b - n, 0LL);
    cout << maxv << ' ' << minv << endl;
    return 0;
}
