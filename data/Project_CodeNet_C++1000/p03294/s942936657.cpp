#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long N;cin>>N;
    long long A[N];
    long long ans=0;
    for(long long i=0;i<N;i++){
        cin>>A[i];
        ans+=A[i]-1;
    }
    cout<<ans<<endl;
}
