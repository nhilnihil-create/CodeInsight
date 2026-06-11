#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

int main(){
    int n;
    cin >> n;
    int a;
    cin >> a;
    rep(i,n-1){
        int b;
        cin >> b;
        a = __gcd(a,b);
        if(a == 1) break;
    }
    cout << a << endl;
    return 0;
}