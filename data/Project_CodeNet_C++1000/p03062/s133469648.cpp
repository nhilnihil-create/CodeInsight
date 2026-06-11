#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    int n;
    cin >> n;
    ll ans = 0, mn = 1e10, cntr = 0;
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        mn = min(mn, abs(a));
        if(a < 0) cntr++;
        ans += abs(a);
    }
    if(cntr % 2) ans = ans - (2 * mn);
    cout << ans;
    return 0;
}
