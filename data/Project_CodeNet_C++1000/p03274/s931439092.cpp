#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int N,K;
    cin>>N>>K;
    long long int ans=2000000000000000000;
    long long int ima=0;
    long long int lis[200000];
    for(int i=0;i<N;i++)cin>>lis[i];
    for(int i=K-1;i<N;i++){
            /*
        if(i<K){
            ima+=lis[i];
        }
        else{
            ima+=lis[i];
            ima-=lis[i-K];
        }
        */
        if(lis[i-K+1]<=0&&0<=lis[i]){
            //printf("[%lld][%lld]\n",lis[i]*2+lis[i-K+1]*-1,lis[i]+lis[i-K+1]*-2);
            ans=min(ans,lis[i]*2+lis[i-K+1]*-1);
            ans=min(ans,lis[i]+lis[i-K+1]*-2);
        }
        else if(lis[i]<=0){
            ans=min(ans,lis[i-K+1]*-1);
        }
        else{

            ans=min(ans,lis[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
