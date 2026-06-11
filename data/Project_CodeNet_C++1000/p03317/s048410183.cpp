#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    ll n,k;
    cin >> n >> k;
    ll ans = (n-2)/(k-1) + 1;
    cout << ans << endl;
}