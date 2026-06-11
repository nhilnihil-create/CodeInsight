#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    ll k,a,b;
    cin >> k >> a >> b;
    ll ans = a;
    k -= a-1;
    if(a+1 < b){
        if(k%2 == 0) cout << k/2*(b-a)+ans << endl;
        else cout << k/2*(b-a)+1+ans << endl;
    }
    else{
        cout << ans+k << endl;
    }
}