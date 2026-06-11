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
    int n,z,w;
    cin>>n>>z>>w;
    vector<int> p(n);
    rep(i,n) cin>>p[i];
    if(n==1){
        cout<<abs(p[0]-w)<<endl;
        return 0;
    }
    int en=p[n-1], enn;
    rep(i,n-1){
        enn=p[n-2-i];
        if(enn!=en) break;
    }
    if(enn==en){
        cout<<abs(w-en)<<endl;
        return 0;
    }else{
        if(abs(enn-en)>abs(en-w)){
            cout<<abs(enn-en)<<endl;
            return 0;
        }else{
            cout<<abs(en-w)<<endl;
            return 0;
        }
    }
    return 0;
}