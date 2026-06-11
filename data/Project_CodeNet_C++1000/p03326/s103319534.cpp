//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main() {
    ll n,m; cin>>n>>m;
    vector<vector<ll>> a(8,vector<ll>(n,0));
    rep(i,n){
        vector<ll> xyz(3,0);
        rep(j,3) cin>>xyz[j];
        rep(j,8){
            rep(k,3){
                if(j&(1<<k)) a[j][i]+=xyz[k];
                else a[j][i]-=xyz[k];
            }
        }
    }
    rep(i,8){
        sort(al(a[i])); reverse(al(a[i]));
    }
    ll ans=0;
    rep(i,8){
        ll cnt=0;
        rep(j,m){
            cnt+=a[i][j];
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
}