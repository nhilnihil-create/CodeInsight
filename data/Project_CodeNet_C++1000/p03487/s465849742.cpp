#include <bits/stdc++.h>
using namespace std;

//082_C

int N,ans,a;

int main(){
    cin>>N;
    int d[N+1]={};
    for(int i=0;i<N;i++){
        cin>>a;
        if(a>N){
            ans++;
        }else {
            d[a]++;
        }
    }
    int sum=0;
    for(int i=0;i<N+1;i++){
        if(d[i]<i){
            ans+=d[i];
        }else {
            ans+=d[i]-i;
        }
    }
    cout<<ans<<endl;
}