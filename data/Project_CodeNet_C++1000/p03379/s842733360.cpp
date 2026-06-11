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
    int n; cin>>n;
    vector<int> p(n),  q(n);
    rep(i,n) cin>>p[i];
    q=p;
    sort(btoe(q));
    rep(i,n){
        if(p[i]<=q[n/2-1]){
            cout<<q[n/2]<<endl;
        }else{
            cout<<q[n/2-1]<<endl;
        }
    }
}