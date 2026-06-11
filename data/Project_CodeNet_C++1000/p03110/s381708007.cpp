#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n;
    cin>>n;
    double ans=0;
    rep(i,n){
        double x; string s;
        cin>>x>>s;
        if(s=="JPY") ans+=x;
        else ans+=x*380000.0;
    }
    cout<<ketasuu(10)<<ans<<endl;
}