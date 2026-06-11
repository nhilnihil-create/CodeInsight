#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

//status unsolved

int main(){
    double n,m,d;
    cin>>n>>m>>d;

    
    double ans;
    
    
    double tmp=n;
        if(n>=2*d+1 && d>0){
        tmp+=(n-2*d);
        }
    
    ans=(double)tmp*(m-1);
    ans/=n;
    ans/=n;
    printf("%.10lf\n",ans);
    
    
    return 0;

}
/*


*/
