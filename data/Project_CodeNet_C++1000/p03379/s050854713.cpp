#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;



int main() {
    int n; cin >> n;
    ll m1,m2;
    vector<ll> x(n),y(n);

    rep(i,n){
        cin >> x[i];
        y[i] = x[i];
    }
    sort(x.begin(),x.end());

    m1 = x[(n-1)/2];
    m2 = x[n/2];

    rep(i,n){
        if(y[i] <= m1) cout << m2 << endl;
        else cout << m1 << endl;
    }
    return 0;
}









