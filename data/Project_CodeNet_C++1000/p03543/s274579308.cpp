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
    if(s[0]==s[1] && s[1]==s[2] || s[1]==s[2] && s[2]==s[3]){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}