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
    string s; cin>>s;
    map<char,int> mp;
    rep(i,3) mp[s[i]]++;
    bool ok=false;
    if(mp['a']*mp['b']*mp['c']==1) ok=true;
    cout<<(ok?"Yes":"No")<<endl;
}