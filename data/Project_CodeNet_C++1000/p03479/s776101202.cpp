#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main() {
    ll x,y; cin >> x >> y;
    ll u=y/x;
    ll ans=0;
    while(u>0){
        u/=2;
        ans++;
    }
    cout << ans << endl;
}