#include <bits/stdc++.h>
using namespace std;


int main(){
    int N,K;
    vector<long> D;
    cin>>N>>K;
    D.resize(N);
    for(int i=0;i<N;i++)cin>>D[i];
    long ans=0;
    for(int i=0;i<=min(N,K);i++){
        for(int j=0;j<=min(N,K)-i;j++){
            long pre=0;
            vector<long> H(i+j);
            for(int k=0;k<i;k++)H[k]=D[k];
            for(int k=0;k<j;k++)H[i+k]=D[N-1-k];
          if(i!=0 || j!=0){
            sort(H.begin(),H.end());
            reverse(H.begin(),H.end());
            for(int k=0;k<K-(i+j);k++)if(H[H.size()-1]<0)H.pop_back();
            for(int k=0;k<H.size();k++)pre+=H[k];
          }
            ans=max(ans,pre);
        }
    }
    cout<<ans<<endl;
}