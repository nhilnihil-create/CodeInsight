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

int main(){
    int n,ans=-inf; cin>>n;
    vector<int> f(n,0);
    rep(i,n)rep(j,10){
        int F; cin>>F;
        f[i]^=(F<<(9-j));
    }
    vector<vector<int>> p(n,vector<int>(11,0));
    rep(i,n)rep(j,11){
        cin>>p[i][j];
    }
    rep(i,(1<<10)){
        if(i==0) continue;
        int cur=0;
        rep(j,n){
            int c=i&f[j],cnt=0;
            rep(k,10)if(c&(1<<k)) cnt++;
            cur+=p[j][cnt];
        }
        ans=max(ans,cur);
    }
    cout<<ans<<endl;
}