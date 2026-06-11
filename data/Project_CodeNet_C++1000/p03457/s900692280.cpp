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
    vector<int> t(n),x(n),y(n);
    rep(i,n) cin>>t[i]>>x[i]>>y[i];
    bool ok=true;
    rep(i,n-1){
        int kari=abs(x[i+1]-x[i])+abs(y[i+1]-y[i])-t[i+1]+t[i];
        if(kari<=0 && kari%2==0){
        }else{
            ok=false;
        }
    }
    int kari=abs(x[0])+abs(y[0])-t[0];
    if(kari<=0 && kari%2==0){

    }else{
        ok=false;
    }
    cout<<(ok?"Yes":"No")<<endl;
}