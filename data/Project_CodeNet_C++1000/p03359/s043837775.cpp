#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main()
{
    ll a, b; cin >> a >> b;
    ll ans = 0;
    if (b > 12) b = 12;
    rep(i,a){
        rep(j,12) {
            if (i == a-1 && j > b-1) continue;
            if ((i+1) == (j+1)) ans++;
        }
    }
    cout << ans << endl;
 
    




}
