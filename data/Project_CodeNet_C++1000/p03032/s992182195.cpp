#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;


int main(){
    int n,k;
    cin >> n >> k;
    vector<int>v(n);
    rep(i,n)cin>>v[i];
    vector<int>l(n);
    vector<int>r(n);
    l[0]=v[0];r[0]=v[n-1];
    rep(i,n-1){
        l[i+1]=l[i]+v[i+1];
        r[i+1]=r[i]+v[n-2-i];
    }
    int ans = 0;
    rep(i,k+1){
        rep(j,i+1){
            vector<int>bag;
            rep(l,j){
                if(bag.size()==n)continue;
                bag.push_back(v[l]);
            }
            rep(l,i-j){
                if(bag.size()==n)continue;
                bag.push_back(v[n-1-l]);
            }
            sort(bag.begin(),bag.end());
            rep(l,min(k-i,(ll)bag.size())){
                if(bag[l]<0)bag[l]=0;
            }
            int tmp = 0;
            rep(l,bag.size()){
                tmp+=bag[l];
            }
            chmax(ans,tmp);
        }
    }
    cout << ans << endl;
    return 0;
}