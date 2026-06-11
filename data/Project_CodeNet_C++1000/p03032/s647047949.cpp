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
    int n,k,ans=-inf,sum=0,cur; cin>>n>>k;
    vector<int> v(n,0),s(n+1,0);
    rep(i,n){
        cin>>v[i];
        sum+=v[i];
        s[i+1]=sum;
    }
    rep(l,n+1)rep(r,n+1){
        if(l+r>min(n,k)) continue;
        int cnt=k-(l+r);
        cur=s[l]+s[n]-s[n-r];
        vector<int> vv;
        rep(i,l) vv.push_back(v[i]);
        rep(i,r) vv.push_back(v[n-1-i]);
        if(vv.size()>0) sort(al(vv));
        rep(i,min(cnt,(int)vv.size())){
            if(vv[i]>=0) break;
            cur-=vv[i];
        }
        ans=max(ans,cur);
    }
    cout<<ans<<endl;
}