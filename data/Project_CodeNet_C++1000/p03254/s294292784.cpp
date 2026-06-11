#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    int N;cin>>N;
    long long x;cin>>x;
    vector<long long> A(N);
    for(long long i=0;i<N;i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    long long ans=0;
    for(long long i=0;i<N;i++){
        if(x>=A[i]){
            ans++;
            x-=A[i];
        }
        else{
            cout<<ans<<endl;
            return 0;
        }
    }
    if(x!=0){
        ans--;
    }
    cout<<ans<<endl;
    return 0;
}