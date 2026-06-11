#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> x(m);
    rep(i,m) cin >> x[i];
    sort(x.begin(), x.end());
    vector<ll> d;
    for(int i = 1; i < x.size(); i++) d.push_back(x[i]-x[i-1]);
    sort(d.begin(), d.end(), greater<ll>());
    ll res = x.back() - x[0];
    rep(i,min((int)d.size(), n-1)) res -= d[i];
    cout << res << endl;
}