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
    int n,k,ans=inf; cin>>n>>k;
    vector<int> x(n,0);
    rep(i,n) cin>>x[i];
    rep(i,n-k+1){
        int dis1=abs(x[i])+abs(x[i]-x[i+k-1]);
        int dis2=abs(x[i+k-1])+(x[i+k-1]-x[i]);
        ans=min(min(dis1,dis2),ans);
    }
    cout<<ans<<endl;
}