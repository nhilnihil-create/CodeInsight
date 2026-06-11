#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize "trapv"
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k; cin>>n>>k;
    ll x = 1;
    for (int i=1;i<=n;i++) {
        x = min(x+k, 2ll*x);
    }
    cout<<x;
    return 0;
}