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
    int n;
    cin>>n;
    int f=n/100;
    int b=n%100;
    bool f_ok = 0 < f && f < 13;
    bool b_ok=  0 < b && b < 13;
    if(f_ok){
        if(b_ok){
            cout<<"AMBIGUOUS";
        }
        else{
            cout<<"MMYY";
        }
    }
    else{
        if(b_ok){
            cout<<"YYMM";
        }
        else{
            cout<<"NA";
        }
    }
}
/*

*/
