#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    ll n,k; cin>>n>>k;
    ll ans=0, c;
    if(k%2==0){
        ll l=k/2;
        if(l<=n){
            c=(n-l)/k+1;
            ans+=c*c*c;
        }
    }
    c=n/k;
    ans+=c*c*c;
    cout<<ans<<endl;
    return 0;
}