#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long N,M;cin>>N>>M;
    long long A[N],B[N];
    vector<pair<long long,long long>>C(N);
    for(int i=0;i<N;i++){
        cin>>A[i]>>B[i];
        C[i].first=A[i];
        C[i].second=B[i];
    }
    sort(C.begin(),C.end());
    long long ans=0;
    for(long long i=0;i<N;i++){
        ans+=min(C[i].second,M)*C[i].first;
        M-=C[i].second;
        if(M<=0){
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
