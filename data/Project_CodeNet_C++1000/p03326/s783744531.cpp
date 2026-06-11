#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

//status unsolved

int main(){
    int n,m;
    cin>>n>>m;
    //long long x[n],y[n],z[n];
    long long cake[n][3];
    //vector<long long>sum(n);
    rep(i,n){
        rep(l,3){
            cin>>cake[i][l];
        }
    }
    int second[3];
    second[0]=1;
    rep2(i,2)second[i]=second[i-1]*2;
    long long ans=-INF;

    for(int bits=0;bits<(1<<3);bits++){
        vector<long long> sum(n,0);
        long long tmp=0;
        rep(i,n){
            rep(l,3){
            if(bits&second[l]){
            sum[i]+=cake[i][l];
            }
            else{
            sum[i]+=cake[i][l]*-1;
            }
            }
        }
        sort(sum.begin(),sum.end());
        reverse(sum.begin(),sum.end());
        rep(i,m)tmp+=sum[i];
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;

}
/*


*/
