#include "bits/stdc++.h"
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(ll i=0;i<n;++i)
#define END(x) (*(x.end()-1))
#define INF INT_MAX / 2

using namespace std;
typedef long long ll;


template<typename T>
T gcd(T a, T b){
   if (a%b == 0){
       return(b);
   }
   else{
       return(gcd(b, a%b));
   }
}

template<typename T>
T lcm(T a,T b){
    return a/gcd(a,b)*b;
}

int main(void){
    cout<<setprecision(20);
    ll k,n;
    cin>>n>>k;
    double ans=0,t=1;
    rep(i,n){
        t=1/(double)n;
        ll a=i+1;
        while(a<k){
            a*=2;
            t/=2.0;
        }
        ans+=t;
    }
    cout<<ans;
}
/*

*/
