#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll a,b,c;
    cin >> a >> b >> c;
    ll ans=0;
    if(b+a>=c){
        ans=b+c;
    }
    else {
        ans=b*2+a+1;
    }
    cout << ans << endl;
}