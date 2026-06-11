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
    ll n,a,b,c,d,e;
    cin>>n>>a>>b>>c>>d>>e;
    cout << max({(n-1)/a,(n-1)/b,(n-1)/c,(n-1)/d,(n-1)/e})+5<<endl;
}
/*
*/