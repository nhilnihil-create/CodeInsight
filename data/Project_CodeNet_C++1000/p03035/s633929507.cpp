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
    int a,b;
    cin>>a>>b;
    if(a>=13){
        cout<<b;
    }
    else if(a>=6){
        cout<<b/2;
    }
    else{
        cout<<0;
    }
}
/*

*/
