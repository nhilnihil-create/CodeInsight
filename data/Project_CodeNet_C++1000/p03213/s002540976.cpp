#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define be begin
#define en end
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ALL(a) (a).be() , (a).en()
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)        //repeat n times
#define REP2(i,s,n) for(int (i)=(s);(i)<(n);(i)++)   //repeat from s to n 
#define REPD(i,n) for(int (i)=(n);(i)>=0;(i)--)      //repeat from n to 0
#define REPD2(i,s,e) for(int (i)=(s);(i)>=(e);(i)--) //repeat from s to e
#define RANGE(i,v) for(auto &(i):v)                  //repeat range
#define ASIZE(a) (sizeof(a) / sizeof(a[0]))          //array size

using LL = long long;

template<typename T> using V = vector< T >;
using Vi = V<int>;
using Vll = V<LL>;
using Vs = V<string>;

template<typename T1,typename T2> using P = pair< T1, T2 >;
using Pii = P<int,int>;
using Pll = P<LL,LL>;
using Pdd = P<double,double>;
using Psi = P<string,double>;

template<typename T1,typename T2> using M = map< T1, T2>;
using Mii = M<int, int>;
using Msi = M<string, int>;

P<Vll,Vll> primeFactor(LL n){
    Vll p,e; LL m=n; int c;
    for(LL i=2;i*i<=n;i++){
        if(m%i!=0){continue;}
        c=0;
        while(m%i==0){c++;m/=i;}
        p.pb(i); e.pb(c);
    }
    if(m>1){ p.pb(m); e.pb(1);}
    return mp(p,e);
}

M<LL,LL> prime_N_kai;
LL num(LL n){
    LL cnt = 0;
    for(auto p : prime_N_kai) if(p.se >= n-1) cnt++;
    return cnt;
}

int main(){
    LL n;
    cin>>n;

    for(LL i=1; i<=n; i++){
        auto pf = primeFactor(i);
        REP(j,pf.fi.size()){
            prime_N_kai[pf.fi[j]] += pf.se[j];
        }
    }

    LL ans = 0;
    ans += num(75);
    ans += num(25) * (num(3)-1);
    ans += num(15) * (num(5)-1);
    ans += (num(5) * (num(5)-1) * (num(3)-2)) / 2;

    cout<<ans<<endl;
    return 0;
}