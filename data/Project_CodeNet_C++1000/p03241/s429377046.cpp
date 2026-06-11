#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


vector<lli> divisor(lli n){
    vector<lli> d;
    for(lli i = 1; i*i <= n; i++){
        if(n%i == 0){
            d.push_back(i);
            if(i != n/i) d.push_back(n/i);
        }
    }
    sort(d.begin(), d.end());
    return d;
}
lli n, m;

int main(void){
    cin >> n >> m;
    auto d = divisor(m);
    lli ans;
    rep(i, d.size()){
        if(d[i] >= n){
            ans = m/d[i];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
