#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll k, a, b; cin >> k >> a >> b;
    ll ans=1;
    if(2<b-a && 2<=k-(a-1)){
        k -= a-1;
        ans += k/2*(b-a) + k%2 + a-1;
    }else{
        ans += k;
    }
    cout << ans << endl;
}
