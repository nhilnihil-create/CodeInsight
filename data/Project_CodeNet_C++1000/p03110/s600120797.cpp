#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    double ans = 0;
    int n; cin >> n;
    vector<double> x(n);
    vector<string> u(n);
    rep(i,n) cin >> x[i] >> u[i];

    rep(i,n){
        ans += (u[i] == "JPY" ? x[i] : x[i] * 380000);
    }

    put(ans);
}