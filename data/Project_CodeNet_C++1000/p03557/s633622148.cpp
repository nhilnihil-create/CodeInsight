//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
//using Graph = vector<vector<pair<ll,ll>>>;
const int mod =1e+9+7;

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
const ll INF=1e10;

int main(){
    ll n; cin>>n;
    vector<ll>a(n),b(n),c(n);
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    rep(i,n)cin>>c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));
    ll ans=0;
    rep(i,n){
        ll up=lower_bound(all(a),b[i])-a.begin();
        ll down=n-(upper_bound(all(c),b[i])-c.begin());
        ans+=up*down;
    }
    cout<<ans<<endl;
}









