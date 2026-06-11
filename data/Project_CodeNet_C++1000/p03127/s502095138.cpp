#include "bits/stdc++.h"
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(ll i=0;i<n;++i)
#define END(x) (*(x.end()-1))
#define INF (INT_MAX / 2)
#define VEC2(type,name,w,h) vector<vector<type>>name(h,vector<type>(w))

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
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,n){
        cin>>a[i];
    }
    rep(i,n-1){
        a[i+1]=gcd(a[i],a[i+1]);
    }
    cout<<a[n-1];
}
/*
*/