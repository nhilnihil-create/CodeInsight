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

int main(){
    LL n,k;
    cin>>n>>k;
    Vll a(n);
    REP(i,n) cin>>a[i];

    Vll k_b2(45);
    LL digit_k = 0;
    LL k_1 = k+1;
    while(k_1>0){
        k_b2[digit_k] += k_1%2;
        k_1 /= 2;
        digit_k++;
    }

    Vll d_num(45);
    LL d_max = 0;
    REP(i,n){
        LL tmp = a[i];
        LL j=0;
        while(tmp>0){
            d_num[j] += tmp%2;
            tmp /= 2;
            j++;
        }
        d_max = max(d_max,j);
    }


    LL x = 0;
    LL ans = 0;
    Vll ni(45);
    ni[0] = 1; 
    REP2(i,1,45) ni[i] = ni[i-1] * 2;
    REPD(i,41){
        if(x+ni[i]>k){
            ans += ni[i] * d_num[i];
        }else{
            if(2*d_num[i] < n) x += ni[i];
            ans += ni[i] * max(d_num[i],n-d_num[i]);
        }
    }

    cout<<ans<<endl;

    return 0;
}