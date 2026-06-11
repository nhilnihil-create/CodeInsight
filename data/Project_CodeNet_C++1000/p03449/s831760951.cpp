#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define rep(i,n) for(int i=0;i<(n);++i)


using namespace std;

typedef long long ll;

int main(){

    int N,tmp,ans;
    scanf("%d",&N);
    
    int A[N+1];
    int B[N+1];
    A[0]=0;
    B[0]=0;

    for(int i=1;i!=N+1;++i){
        scanf("%d",&tmp);
        A[i]=A[i-1]+tmp;
    }
    for(int i=1;i!=N+1;++i){
        scanf("%d",&tmp);
        B[i]=B[i-1]+tmp;
    }
    /*
    rep(i,N+1)cout<<A[i]<<" ";
    cout<<endl;
     rep(i,N+1)cout<<B[i]<<" ";
    cout<<endl;
    */
    ans=0;

    for(int i=0;i!=N+1;++i){
        //cout<<"tmp:"<<tmp<<endl;
        tmp=A[i]-A[0]+B[N]-B[i-1];
        ans=tmp>=ans?tmp:ans;
    }

    cout<<ans<<endl;
}