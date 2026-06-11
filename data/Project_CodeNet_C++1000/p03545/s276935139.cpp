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
    string s; cin>>s;
    vector<int> p(4);
    rep(i,4) p[i]=s[i]-'0';
    rep(i,1<<3){
        int kari=p[0];
        rep(j,3){
            if(i>>j&1){
                kari+=p[j+1];
            }else{
                kari-=p[j+1];
            }
        }
        if(kari==7){
            string ans;
            ans+=s[0];
            rep(j,3){
                if(i>>j&1){
                    ans+='+';
                    ans+=s[j+1];
                }else{
                    ans+='-';
                    ans+=s[j+1];
                }
            }
            ans+="=7";
            cout<<ans<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}