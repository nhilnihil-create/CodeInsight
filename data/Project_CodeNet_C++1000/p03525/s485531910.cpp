#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    int n;
    cin>>n;
    if(n>=24){
        cout<<0<<endl;
        return 0;
    }
    int d[n];
    rep(i,n)cin>>d[i];
    int ans=0;
    rep(s,1<<n){
        int cnt[24]={1};
        bool flag=true;
        rep(i,n){
            if(s&(1<<i)){
                if(cnt[d[i]]){
                    flag=false;
                }
                ++cnt[d[i]];
            }
            else{
                if(d[i]==0||cnt[24-d[i]]){
                    flag=false;
                }
                ++cnt[24-d[i]];
            }
        }
        if(!flag)continue;
        int mn=inf;
        int mx=0;
        for(int i=1;i<=23;++i){
            if(cnt[i]){
                mn=min(mn,i-mx);
                mx=i;
            }
        }
        mn=min(mn,24-mx);
        ans=max(ans,mn);
    }
    cout<<ans<<endl;
}
