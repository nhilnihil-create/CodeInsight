#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll k,a,b;cin >> k >> a >> b;
    if(b-a<2 || k-a<1){
        cout << k+1 << endl;
        return 0;
    }

    k -= a-1;
    int y=0;
    if(k%2==1) y=1;
    ll ans=a;
    ans += k/2*(b-a);
    ans += y;
    cout << ans << endl;
    return 0;
}