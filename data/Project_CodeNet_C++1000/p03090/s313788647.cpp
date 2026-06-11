#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;

//入力
ll n;

int main(){
    cin >> n;
    vector<P> ans;
    if(n%2==0){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(i+j==n+1)continue;
                ans.push_back({i,j});
            }
        }
    }
    else{
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(i+j==n)continue;
                ans.push_back({i,j});
            }
        }
    }
    ll m = ans.size();
    cout << m << endl;
    rep(i,m){
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
    return 0;
}
