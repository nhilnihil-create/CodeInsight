#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main() {
    ll n; cin >> n;
    vector<ll> x(n),y(n);
    rep(i,n){
        cin >> x[i];
        y[i]=x[i];
    }
    sort(y.begin(),y.end());
    ll MID = n/2;
    ll mid = n/2-1;
    ll M=y[MID];
    ll m=y[mid];
    rep(i,n){
        if(x[i]>=M) cout << m;
        else cout << M;

        cout << endl;
    }
}