#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n);i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int n,m;

int main(){
    cin>>n>>m;
    vector<int> x(m);
    rep(i,0,m) cin>>x[i];
    sort(x.begin(),x.end());
    vector<int> ans(m-1);
    rep(i,0,m-1) ans[i]=x[i+1]-x[i];
    int sum=0;
    sort(ans.begin(),ans.end());
    rep(i,0,m-n) sum+=ans[i];
    cout<<sum<<"\n";
    return 0;
}
