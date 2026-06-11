#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    ll a,b,c,k;
    cin >> a >> b >>  c>> k;
    ll ans;

    ans = a-b;
    if(k%2 == 1) cout << -ans <<endl;
    else        cout << ans << endl;
}