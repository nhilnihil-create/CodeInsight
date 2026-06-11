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
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
//cin.tie(0);
//ios::sync_with_stdio(false);

ll judge(vector<vector<char>> &v,ll x){
    ll n=siz(v);

    for(int i=0;i < siz(v);i++)
    {
        for(int j=0;j < siz(v);j++)
        {
            if(v[(i-x+n)%n][(j)%n]!=v[(j-x+n)%n][(i)%n]){
                return 0;
            }
        }
    }

    return n;
}

signed main(){
    int n;cin>>n;
    ll ans=0;
    vector<vector<char>> v(n,vector<char>(n));
    rep(i,n)rep(j,n){
        cin>>v[i][j];
    }

    
    rep(i,n){
        ans+=judge(v,i);
    }

    cout<<ans<<endl;

}	