#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<P> d(n);
    rep(i,n){
        int a, b;
        cin >> a >> b;
        d[i] = P(a,b);
    }
    sort(d.begin(), d.end());
    ll ans = 0;
    rep(i,n){
        ll a = d[i].first, b = d[i].second;
        if(m < b){
            ans += a*m;
            break;
        }
        else{
            ans += a*b;
            m -= b;
        }
    }
    cout << ans << endl;
}