#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    ll n, keta = 0;
    cin >> n;
    if(n<=9) {cout << n << endl; return 0;}
    n++;
    ll temp = n;
    while(temp/10){
        keta++;
        temp/=10;
    }
    ll ans= 0;
    rep(i,keta){
        ans+=9;
    }
    ans+=(temp-1);
    cout << ans << endl;
    return 0;
}