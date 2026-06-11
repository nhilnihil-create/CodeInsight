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
    ll n,m,ans=0; cin>>n>>m;
    vector<ll> a(n,0),sum(n+1,0);
    map<ll,ll> q;
    q[0]=1;
    rep(i,n){
        cin>>a[i];
        sum[i+1]=(sum[i]+a[i])%m;
        if(q.count(sum[i+1])) q[sum[i+1]]++;
        else q[sum[i+1]]=1;
    }
    for(auto p : q){
        ans+=p.second*(p.second-1)/2;
    }
    cout<<ans<<endl;
}