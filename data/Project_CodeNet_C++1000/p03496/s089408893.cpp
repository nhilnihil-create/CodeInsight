#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repi(i,x,n) for(ll i=x;i<(ll)(n);i++)
#define lb lower_bound
#define ub upper_bound
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
//cin.tie(0);ios::sync_with_stdio(false);



signed main(){
    ll n;cin>>n;
    vector<ll> v(n);
    rep(i,n)cin>>v[i];
    vector<PL> ans(0);


    for(int i=n-1;0<i;i--)
    {
        while(abs(v[i-1])<abs(v[i]) && v[i-1]>v[i]){
            v[i-1]+=v[i];
            ans.pb({i+1,i});
        }
    }

    for(int i=1;i<n;i++)
    {
        while(v[i-1]>v[i] && abs(v[i-1])>abs(v[i])){
            
            v[i]+=v[i-1];
            ans.pb({i,i+1});
        }
    }

    cout<<siz(ans)<<endl;
    rep(i,siz(ans)){
        cout<<ans[i].fi<<" "<<ans[i].se<<endl;
    }
}