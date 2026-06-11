#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n,t;
    cin>>n>>t;
    int ans=100000;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        if(b<=t) ans=min(ans,a);
    }
    if(ans==100000) cout<<"TLE"<<endl;
    else cout<<ans<<endl;
}