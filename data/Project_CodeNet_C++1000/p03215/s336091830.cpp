#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

//status unsolved

int main(){
    long long n,k;
    cin>>n>>k;
    long long a[n];
    long long sum[n+1];
    sum[0]=0;
    rep(i,n)cin>>a[i];

    rep(i,n)sum[i+1]=sum[i]+a[i];
    
    long long second[45];
    second[0]=1;
    rep(i,44)second[i+1]=second[i]*2;

    long long ans=0;
    long long SIZE=(n*(n+1))/2;
    vector<long long>part_sum(SIZE);
    long long now=0;
    for(int i=0;i<n;i++){
        for(int l=i+1;l<=n;l++){
            part_sum[now++]=sum[l]-sum[i];
        }
    }
    for(int i=44;i>-1;i--){
        int cnt=0;
        bool select[SIZE]={};

        rep(l,SIZE){
            if(part_sum[l]<0)continue;

            if(second[i]&part_sum[l]){
                select[l]=true;
                cnt++;
            }
        }

        if(cnt>=k){
            ans|=second[i];
            rep(l,SIZE){
                if(!select[l]){
                part_sum[l]=-1;
                }
            }
        }
    }
    //cout<<second[44]<<endl;
    cout<<ans<<endl;
    return 0;

}
/*


*/
