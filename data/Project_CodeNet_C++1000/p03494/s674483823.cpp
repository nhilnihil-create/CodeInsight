#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()
#define chmax(x,y) x=max(x,y)


const int inf=2e9+5;

int main(){
    int n; cin>>n;
    vector<int> p(n);
    rep(i,n) cin>>p[i];
    int ans=inf;
    rep(i,n){
        int kari=0;
        while(p[i]%2==0){
            kari++;
            p[i]/=2;
        }
        ans=min(ans, kari);
    }
    cout<<ans<<endl;
    return 0;
}