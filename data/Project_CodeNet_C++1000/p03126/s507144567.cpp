#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,M;cin>>N>>M;
    vector<int>B(M,0);
    for(int i=0;i<N;i++){
        int K;
        cin>>K;
        for(int l=0;l<K;l++){
            int A;
            cin>> A;
            B[A-1]++;
        }
    }
    int ans=0;
    for(int i=0;i<M;i++){
        if(B[i]==N){
            ans++;
        }
    }
    cout<<ans<<endl;
}