#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

ll lcm(ll a, ll b){
    return a*b / gcd(a, b);
}


int main() {

    ll n,x; cin >> n >> x;
    ll ans = 0;
    ll tmp;

    cin >> tmp;
    ans = abs(tmp-x);
    for(int i = 1; i < n; i ++){
         cin >> tmp;
        ans = gcd(ans,abs(tmp-x));
    }
    cout << ans;
    return 0;
}









