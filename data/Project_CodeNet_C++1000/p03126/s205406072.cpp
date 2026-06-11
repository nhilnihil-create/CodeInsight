#include<iostream>
using namespace std;
int main(){
    int N,M,i,j,t,K,sum=0;
    cin>>N>>M;
    int a[M]={0};
    for(i=1;i<=N;i++){
        cin>>K;
        for(j=1;j<=K;j++){
            cin>>t;
            a[t-1]++;
        }
    }
    for(i=0;i<M;i++){
        if(a[i]==N){
            sum++;
        }
    }
    cout<<sum;
    return 0;

}