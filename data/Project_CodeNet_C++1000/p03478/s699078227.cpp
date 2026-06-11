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
    int n,a,b; cin>>n>>a>>b;
    int ans=0;
    for(int i=1; i<=n; ++i){
        string s=to_string(i);
        int kari=0;
        for(auto &v: s){
            kari+=v-'0';
        }
        if(a<=kari && kari<=b) ans+=i;
    }
    cout<<ans<<endl;
    return 0;
}