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

int main(){
    int N,K;
    cin>>N>>K;

    LL cnt_0 = 0;
    LL cnt_k_2 = 0;
    REP2(i,1,N+1){
        if(i%K==0) cnt_0++;
        if(i%K==K/2) cnt_k_2++;
    }

    if(K%2==1){
        cout<<cnt_0*cnt_0*cnt_0<<endl;
    }else{
        cout<<cnt_0*cnt_0*cnt_0+cnt_k_2*cnt_k_2*cnt_k_2<<endl;
    }

    return 0;
}