#include "bits/stdc++.h"
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(ll i=0;i<n;++i)
#define END(x) (*(x.end()-1))
#define INF (INT_MAX / 2)

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
    ll n,m;
    cin>>n>>m;
    ll L=1,R=n;
    ll l,r;
    rep(i,m){
        cin>>l>>r;
        L=max(L,l);
        R=min(R,r);
    }
    if(L>R){
        cout<<0;
        return 0;
    }
    cout<<R-L+1;
}
/*

*/
