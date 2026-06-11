#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);
    ll ans=0;
    rep(i,n){
        while(a.at(i)%2==0){
            ans++;
            a.at(i)/=2;
        }
    }
    cout << ans << endl;
}
