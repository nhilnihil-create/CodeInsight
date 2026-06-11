#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long N;cin>>N;
    vector<long long>A(N);
    for(long long i=0;i<N;i++){
        cin>>A[i];
    }
    long long ans,tmp;ans=tmp=0;
    for(long long i=0;i<N;i++){
        tmp=0;
        while(A[i]%2==0){
            A[i]/=2;
            tmp++;
        }
        ans+=tmp;
    }
    cout<<ans<<endl;
    return 0;
}
