#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

//status unsolved

int main(){
    long long n,K;
    cin>>n>>K;
    long long s[n+1];
    s[0]=0;
    rep(i,n){
        long long a;
        cin>>a;
        s[i+1]=s[i]+a;
    }
    vector<long long>beauty((n*(n+1))/2);
    long long cur=0;
    for(int i=0;i<n;i++){
        for(int k=i+1;k<=n;k++){
            beauty[cur]=(s[k]-s[i]);
            cur++;
        }
    }
    long long int second[45];
    int p=0;
    second[0]=1;
    rep(i,44){
        second[i+1]=second[i]*2;
        if(second[i]<0)break;
        
    }
    
    
    long long ans=0;
    
    long long  all=beauty.size();

    for(int i=44;i>-1;i--){
        
        long long  cnt=0;
        for(int k=0;k<all;k++){
            if(beauty[k]<0)continue;
            
            if(((second[i]+ans)&beauty[k])==(ans+second[i])){
                cnt++;
            }
        }
        
        if(cnt>=K){
            ans|=second[i];
        }
    }
    //cout<<endl;
    
    cout<<ans<<endl;
    
    return 0;

}
/*
4 2
2 5 2 5

12


*/
