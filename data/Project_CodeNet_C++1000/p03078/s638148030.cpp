#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    ll x,y,z,K;
    cin >> x >> y >> z >> K;
    vector<ll>a(x),b(y),c(z);
    vector<ll>ans;
    rep(i,x) {
        cin >> a[i];
    }
    rep(i,y) {
        cin >> b[i];
    }
    rep(i,z) {
        cin >> c[i];
    }
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    sort(c.rbegin(),c.rend());
    rep(i,x) rep(j,y) {
        if((i+1)*(j+1) > K) continue;
        rep(k,z) {
            if((i+1)*(j+1)*(k+1) > K) continue;
            ans.push_back(a[i]+b[j]+c[k]);
        }
    }
    sort(ans.rbegin(),ans.rend());
    rep(i,K) cout << ans[i] << endl;
    
    
}