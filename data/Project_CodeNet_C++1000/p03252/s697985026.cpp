#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    string s,t;
    cin>>s>>t;
    map<char,char> mp,np;
    int n=s.size();
    rep(i,n) mp[s[i]]=t[i];
    rep(i,n) np[t[i]]=s[i];
    bool ok=true;
    rep(i,n){
        if(mp[s[i]]!=t[i]) ok=false;
        if(np[t[i]]!=s[i]) ok=false;
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}