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
    string s,t; cin>>s>>t;
    sort(btoe(s)); sort(etob(t));
    int ok=0;
    rep(i,min(s.size(), t.size())){
        if(s[i]<t[i]){
            ok=1;
            break;
        }else if(s[i]>t[i]){
            ok=-1;
            break;
        }
    }
    if(ok==0){
        if(s.size()<t.size()){
            ok=1;
        }else{
            ok=-1;
        }
    }
    if(ok==1){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}