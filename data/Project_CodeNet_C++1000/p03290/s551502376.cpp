#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int d,g;
    cin>>d>>g;
    vector<int>p(d),c(d);
    rep(i,d)cin>>p[i]>>c[i];
    int ans=1e9;
    for(int bit=0; bit<(1<<d); ++bit){
        int mn=0,cnt=0;
        vector<bool>a(d,false);
        rep(i,d){
            if(bit&(1<<i)){
                mn+=p[i];
                cnt+=(i+1)*100*p[i]+c[i];
                a[i]=true;
            }
        }
        if(cnt>=g){
            ans=min(ans,mn);
        }
        else{
            for(int i=d-1; i>=0; --i){
                if(a[i])continue;
                for(int j=0; j<p[i]; ++j){
                    cnt+=(i+1)*100;
                    mn++;
                    if(cnt>=g){
                        ans=min(ans,mn);
                        break;
                    }
                }
                if(cnt>=g)break;
            }
        }
    }
    cout<<ans<<endl;
}