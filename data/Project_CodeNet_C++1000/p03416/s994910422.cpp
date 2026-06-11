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
    int a,b,ans=0;
    cin>>a>>b;
    for(int i=a; i<=b; ++i){
        if(i/10000==i%10 && (i/1000)%10==(i/10)%10){
            //cout<<i<<endl;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}