#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()


const int inf=2e9;

int main(){
    int n,g; cin>>n>>g;
    vector<int> p(n),c(n);
    rep(i,n) cin>>p[i]>>c[i];
    int ans=inf;
    rep(i,1<<n){
        vector<int> che(n,0);
        rep(j,n) if(i>>j&1) che[j]=1;
        int cnt=0, kari=0;
        rep(j,n){
            if(che[j]==1){
                cnt+=p[j]; kari+=(p[j]*(j+1)*100+c[j]);
            }
        }
        if(kari<g){
            int num=-1;
            rep(j,n){
                if(che[j]==0) num=j;
            }
            if(num==-1) continue;
            int kosu=(g-kari+(num+1)*100-1)/((num+1)*100);
            if(kosu<p[num]){
                cnt+=kosu;
            }
            else continue;
        }
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}