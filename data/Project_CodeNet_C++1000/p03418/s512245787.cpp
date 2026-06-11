#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin >> n >> k;

    ll ans=0;

    if(k==0){
        cout << n*n << "\n";
        return 0;
    }

    for(int b = k+1; b <= n; b++) {
        ll tans=(b-k)*(n/b)+max(ll(0),n%b-k+1);
//        cout << b << ":" << tans << "\n";
        ans+=tans;
    }
    cout << ans << "\n";

    return 0;
}