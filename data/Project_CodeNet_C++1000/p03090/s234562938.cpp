#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll n;cin>>n;
    vector<pll>ans(0);
    ll s;
    if(n%2)s=n;
    else s=n+1;
    REP(i,1,n+1){
        REP(j,i+1,n+1){
            if(s-i!=j)ans.pb(mp(i,j));
        }
    }
    cout<<ans.size()<<endl;
    rep(i,ans.size()){
        cout<<ans[i].first<<' '<<ans[i].second<<endl;
    }
}