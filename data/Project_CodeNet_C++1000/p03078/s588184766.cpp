#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    ll x,y,z,k;
    cin >> x >> y >> z >> k;
    vector<ll>a(x),b(y),c(z);
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
    vector<ll>e;
    rep(i,x) rep(j,y) {
        e.push_back(a[i]+b[j]);
    }
    sort(e.rbegin(),e.rend());
    
    
    vector<ll>ans;
    int n = min((ll)e.size(),k);
    //a+bの大きい方からk個とcの組み合わせを全探索し
    //その中から大きいものｋ個が答え
    rep(i,n) rep(j,z) {
        ans.push_back(e[i]+c[j]);
    }
    sort(ans.rbegin(),ans.rend());
    
    rep(i,k)cout << ans[i] << endl; 
}