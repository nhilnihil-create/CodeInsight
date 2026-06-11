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

LL f(Vll a, LL b){
    LL sum_ab = 0;
    for( LL i : a){
        sum_ab += abs(i-b);
    }
    return sum_ab;
}

int main(){
    int N;
    cin>>N;
    Vll A(N);
    REP(i,N) cin>>A[i];
    Vll AA(N);
    REP(i,N) AA[i] = A[i] - (i+1);
    sort(ALL(AA));
    if(N%2==1){
        cout<<f(AA,AA[N/2])<<endl;
    }else{
        cout<<(f(AA,AA[N/2])+f(AA,AA[N/2-1]))/2<<endl;
    }
    return 0;
}