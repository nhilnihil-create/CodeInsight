#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    ll k, a, b;
    cin >> k >> a >> b;
    ll ans = k+1;
    ll l = k-(a-1);
    if(l >= 0){
        ans = max(ans, l/2*(b-a) + a + l%2);
    }

    cout << ans << endl;
    return 0;
}