#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n,k; cin>>n>>k;
    vector<int> p(n);
    rep(i,n) cin>>p[i];
    if(n==k){
        cout<<1<<endl;
        return 0;
    }
    int che;
    rep(i,n) if(p[i]==1) che=i;
    int ch=n-1-che;
    int ans=(ch+che+k-2)/(k-1);
    cout<<ans<<endl;
    return 0;
}