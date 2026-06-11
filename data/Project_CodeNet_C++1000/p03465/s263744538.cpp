#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;



int main(){

    int n;
    cin>>n;
    int A[n+1];

    rep2(i,n)cin>>A[i];
    
    bitset<4000010>bs;
    int cnt[4000010]={};
    bs[0]=1;
    long long sum=0;
    rep2(i,n){
        bs|=(bs << A[i]);
        sum+=A[i];
    }

    for(int i=++sum/2;;i++){
        if(bs[i]){
            cout<<i<<endl;
            return 0;
        }
    }

    /*
    long long ans;
    long long median=1;

    rep(i,n-1)median*=2;

    cout<<median<<endl;
    rep2(i,4000010){
        if(bs[i]==1){
            cout<<i;
        }
    }
    cout<<endl;
    */

    

    return 0;

}
/*


*/
