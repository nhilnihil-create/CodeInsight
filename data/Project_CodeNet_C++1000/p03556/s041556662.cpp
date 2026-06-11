#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    ll n;
    cin >> n;
    ll i = 1;
    ll ans = 0;
    while(i*i <= n){
        ans = i*i;
        i++;
    }
    cout << ans << endl;
    return 0;
}