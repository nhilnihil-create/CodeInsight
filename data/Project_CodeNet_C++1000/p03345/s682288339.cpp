#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=2e5+5;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll a,b,c,k;cin>>a>>b>>c>>k;
    ll ans = a-b;
    if(k&1)ans*=-1;

    cout<<ans;
}

    /*
        a b c
        b+c a+c a+b

        2*a+b+c a+2*b+c a+b+2*c

        2a+3b+3c 3a+2b+3c 3a+3b+2c

    |a-b|
*/
