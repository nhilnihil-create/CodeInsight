#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a, b, c, k; cin >> a >> b >> c >> k;
    ll ans=0;
    if(k%2==1) ans = b-a;
    else ans = a-b;
    if(1e+18<abs(ans)){
        cout << "Unfair" << endl;
    }
    else cout << ans << endl;
    


}