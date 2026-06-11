#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
                     
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
const ll mod = 1e9+7;
ll mult(ll a,ll b){return ((a%mod)*(b%mod))%mod;}
ll add(ll a,ll b){return ((a%mod)+(b%mod))%mod;}
ll sub(ll a,ll b){return ((a%mod)-(b%mod)+mod)%mod;} 
int n;
vector<int> h, a;
vector<ll> dp;

vector<ll> tree(1000000);
vector<ll> lazy(4000005);
void update(ll tl,ll tr, ll tind, ll nval, ll arrind){
    if(tr==tl){
        tree[tind] = nval;
        return;
    }
    ll m = tl + (tr - tl)/2;
    if(arrind<=m)
        update(tl,m,tind*2,nval,arrind);
    else
        update(m+1,tr,tind*2+1,nval,arrind);

    tree[tind] = max(tree[tind*2], tree[tind*2+1]);

}

ll range_query(ll tl, ll tr, ll tind, ll l, ll r){
    if(l>tr || r<tl){
        return 0;
    }
    else if(l<=tl && r>=tr){
        return tree[tind];
    }
    else{
        ll m = tl + (tr-tl)/2;
        return max(range_query(tl,m,tind*2,l,r), range_query(m+1,tr,tind*2+1,l,r));
    }
}
ll build(ll tl,ll tr, ll i){
    if(tl == tr){
        return tree[i] = 0;
    }
    ll m = tl + (tr-tl)/2;
    return tree[i] = max(build(tl,m,2*i), build(m+1,tr,2*i+1));
}
int solve(){
    cin>>n;
    h.resize(n), a.resize(n), dp.resize(n);
    for(int i=0;i<n;++i){
        cin>>h[i];
    }
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    dp.resize(n + 1);
    build(1, n, 1);
    ll ans = 0;
    for(int i=0;i<n;++i){
        // find maximum beauty for height in range (1, h[i]-1)
        ll maxi = range_query(1, n, 1, 1, h[i]-1);
        dp[i] = a[i]+ maxi;
        ans = max(ans, dp[i]);
        update(1, n, 1, dp[i], h[i]);
        // update segment tree for height = h[i];
    }
    cout<<ans;
    return 0;
}
int main(){
    fast;
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}