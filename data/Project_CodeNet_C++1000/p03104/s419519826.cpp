#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

ll odd(ll x){ return (x+1)/2 % 2;}
ll cal(ll x){
    if(x%2==1) return odd(x);
    else return odd(x+1) ^ (x+1);
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll ans = cal(b) ^ cal(a-1);
    cout << ans << endl;
    return 0;
}