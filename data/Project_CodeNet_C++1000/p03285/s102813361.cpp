#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n; cin>>n;
    vector<int> p,q;
    rep(i,26) p.push_back(4*(i));
    rep(i,16) q.push_back(7*(i));
    bool ok=false;
    rep(i,25){
        rep(j,15){
            if(n==(p[i]+q[j])) ok=true;
        }
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}