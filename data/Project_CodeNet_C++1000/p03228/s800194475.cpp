#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll a,b,k;
    cin >> a >> b >> k;
    for(ll i=0;i<k;i++){
        if(i%2==0){
            if(a%2==1) a--;
            a/=2;
            b+=a;
        }
        else {
            if(b%2==1) b--;
            b/=2;
            a+=b;
        }
    }
    cout << a << " " << b << endl;
}