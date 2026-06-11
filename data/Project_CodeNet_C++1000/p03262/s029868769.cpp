#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()


int gcd(int a,int b){return(a? gcd(b%a,a): b);}

int main(){
    int n; cin>>n;
    vector<int> p(n);
    int x; cin>>x;
    rep(i,n){
        cin>>p[i];
        p[i]=abs(p[i]-x);
    }
    if(n==1){
        cout<<p[0]<<endl;
        return 0;
    }
    int ans=gcd(p[0],p[1]);
    rep(i,n-2) ans=gcd(ans,p[i+2]);
    cout<<ans<<endl;
    return 0;
}