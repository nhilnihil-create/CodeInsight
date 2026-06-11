#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n; cin>>n;
    vector<int> c(n-1), s(n-1), f(n-1);
    rep(i,n-1) cin>>c[i]>>s[i]>>f[i];
    rep(i,n-1){
        int ans=s[i]+c[i];
        for(int j=i; j<n-2; ++j){
            if(ans<=s[j+1]){
                ans=s[j+1]+c[j+1];
            }else{
                int kari=(ans-s[j+1]+f[j+1]-1)/f[j+1];
                ans=s[j+1]+kari*f[j+1]+c[j+1];
            }
        }
        cout<<ans<<endl;
    }
    cout<<0<<endl;
    return 0;
}