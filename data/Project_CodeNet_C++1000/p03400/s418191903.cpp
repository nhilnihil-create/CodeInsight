#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    int N,D,X;cin>>N>>D>>X;
    int A[N];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int ans=X;
    for(int i=0;i<N;i++){
        ans+=1+(D-1)/A[i];        
    }
    cout<<ans<<endl;
    return 0;
}