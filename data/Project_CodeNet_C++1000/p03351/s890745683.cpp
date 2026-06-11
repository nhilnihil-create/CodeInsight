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
    int a,b,c,d; cin>>a>>b>>c>>d;
    bool ok=false;
    if(abs(a-c)<=d) ok =true;
    if(abs(a-b)<=d && abs(b-c)<=d) ok=true;
    cout<<(ok?"Yes": "No")<<endl;
}