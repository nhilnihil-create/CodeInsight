#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    int x,y,z,k;
    cin >> x >> y >> z >> k;
    vector<ll>a(x),b(y),c(z);
    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];
    vector<ll>e;
    rep(i,x) {
        rep(j,y) {
            e.push_back(a[i]+b[j]);
        }
    }
    sort(e.rbegin(),e.rend());
    // rep(i,x*y) cout << e[i] << endl;
    vector<ll>ans;
    rep(i,min(x*y,k)) {
        rep(j,min(z,k)) {
            ans.push_back(e[i]+c[j]);
        }
    }
    sort(ans.rbegin(),ans.rend());
    rep(i,k) cout << ans[i] << endl;
}