#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF=1001001001;

int main(){
    int n,m;
    cin>>n>>m;
    vector<P>x(m);
    rep(i,m){
        int a,b; cin>>a>>b;
        x[i]=P(a,b);
    }
    sort(x.begin(),x.end());
    int mn=-1,mx=INF,ans=0;
    rep(i,m){
        mn=max(mn,x[i].first);
        mx=min(mx,x[i].second);
        if(mn>=mx){
            ans++;
            mn=x[i].first;
            mx=x[i].second;
        }
    }
    ans++;
    cout<<ans<<endl;
}