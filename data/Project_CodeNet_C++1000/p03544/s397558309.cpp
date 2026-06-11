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




int main(){
    int n; cin>>n;
    vector<ll> p(87);
    p[0]=2;
    p[1]=1;
    rep(i,85){
        p[i+2]=p[i+1]+p[i];
    }
    cout<<p[n]<<endl;
}