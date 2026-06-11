#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int cnt[13],vis[24];

int count(){
    int mi=101010;
    rep(i,24) rep(j,24){
        if(vis[i] && vis[j] && i!=j){
            int d1=abs(i-j);
            int d2=24-d1;
            int d=min(d1,d2);
            mi=min(mi,d);
        }
    }
    return mi;
}

int main(){
    int n;
    cin>>n;
    vector<int> d(n);
    rep(i,n) cin>>d[i];

    rep(i,n) cnt[d[i]]++;
    if(cnt[0]){
        cout<<0<<endl;
        return 0;
    }
    vis[0]=1;

    vector<int> v;
    for(int i=1;i<12;i++){
        if(cnt[i]==1) v.push_back(i);
        else if(cnt[i]==2) vis[i]=vis[24-i]=1;
        else if(2<cnt[i]){
            cout<<0<<endl;
            return 0;
        }
    }

    if(cnt[12]==1) vis[12]=1;
    else if(cnt[12]>=2){
        cout<<0<<endl;
        return 0;
    }

    int m=v.size();
    if(m==0){
        cout<<count()<<endl;
        return 0;
    }
    
    int ans=0;
    rep(msk,1<<m){
        rep(i,m){
            if(msk & 1<<i) vis[v[i]]=1, vis[24-v[i]]=0;
            else vis[v[i]]=0, vis[24-v[i]]=1;
        }
        ans=max(ans,count());
    }

    cout<<ans<<endl;
}