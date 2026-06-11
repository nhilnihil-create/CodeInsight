#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
using ll = long long;
using namespace std;
ll pow2(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n&1){
            res=res*a;
        }
        a=a*a;
        n>>=1;
    }
    return res;
}
int main(){
    int n,k;
    cin>>n>>k;
    double ans=0;
    rep(i,n){
        int a=i+1;
        double tmp=1.0/n;
        while(a<k){
            a*=2;
            tmp/=2;
        }
        ans+=tmp;
    }
    cout<<fixed<<setprecision(15)<<ans<<endl;
}