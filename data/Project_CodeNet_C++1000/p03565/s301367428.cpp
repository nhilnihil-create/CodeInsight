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
    string s,t; cin>>s>>t;
    bool ok=false;
    rep(i, s.size()-t.size()+1){
        bool che=true;
        rep(j,t.size()){
            if(s[j+s.size()-t.size()-i]==t[j] || s[j+s.size()-t.size()-i]=='?'){

            }else{
                che=false;
                break;
            }
        }
        if(che){
            rep(j,t.size()){
                s[j+s.size()-t.size()-i]=t[j];
                ok=true;
            }
            break;
        }
    }
    if(ok){
        rep(i, s.size()){
            if(s[i]=='?'){
                s[i]='a';
            }
        }
        cout<<s<<endl;
    }else{
        cout<<"UNRESTORABLE"<<endl;
    }
    return 0;
}