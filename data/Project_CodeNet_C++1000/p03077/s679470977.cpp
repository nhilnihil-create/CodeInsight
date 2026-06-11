#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

int main(){
    ll m=10000000000000000;
    ll n; cin >> n;
    vector<ll> a(5);
    rep(i,5){
        cin >> a[i];
        m=min(m,a[i]);
    }
    ll x=(n+m-1)/m;
    cout << x+4 << endl;
}