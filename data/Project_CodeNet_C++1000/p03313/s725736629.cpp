#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define inf (int)(3e18)
#define P pair<int,int>
#define mod (int)(1e9+7)
#define mod2 998244353

template<class T> inline void chmin(T &a, T b) {
	a = min(a, b);
}
template<class T> inline void chmax(T &a, T b) {
	a = max(a, b);
}

int N;
P mx1[1<<18],mx2[1<<18];
signed main(){
    cin>>N;
    rep(i,1<<N){
        cin>>mx1[i].first;
        mx1[i].second=i;
        mx2[i].second=-1;
    }
    int ans=0;
    rep(i,1<<N){
        chmax(ans,mx1[i].first+mx2[i].first);
        if(i)cout<<ans<<endl;
        rep(j,N){
            if(i>>j&1)continue;
            int k=i|(1<<j);
            if(mx1[k].first<=mx1[i].first&&mx1[k].second!=mx1[i].second&&mx2[k].second!=mx1[i].second){
                mx2[k]=mx1[k];
                mx1[k]=mx1[i];
            }else if(mx2[k].first<=mx1[i].first&&mx2[k].second!=mx1[i].second&&mx1[k].second!=mx1[i].second){
                mx2[k]=mx1[i];
            }
            if(mx2[k].first<=mx2[i].first&&mx2[k].second!=mx2[i].second&&mx1[k].second!=mx2[i].second){
                mx2[k]=mx2[i];
            }
        }
    }
}