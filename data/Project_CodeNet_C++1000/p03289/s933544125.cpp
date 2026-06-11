#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    string s; cin>>s;
    int n=s.length();
    bool ok=true;
    if(s[0]!='A') ok=false;
    int cnt=0;
    for(int i=2; i<n-1; ++i){
        if(s[i]=='C') cnt++;
    }
    if(cnt!=1) ok=false;
    cnt=0;
    rep(i,n){
        if(isupper(s[i])) cnt++;
    }
    if(cnt!=2) ok=false;
    cout<<(ok?"AC":"WA")<<endl;
}