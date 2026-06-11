#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main(){
    ll x,y;
    cin >> x >> y;
    int ans = 0;
    while(y >= x){
        x *= 2;
        ans += 1;
    }
    cout << ans << endl;
}