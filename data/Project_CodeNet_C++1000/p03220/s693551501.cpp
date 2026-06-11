#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long N,T,A;cin>>N>>T>>A;
    vector<long long>H(N);
    double near=9999999.99;
    long long ans=0;
    for(long long i=0;i<N;i++){
        cin>>H[i];
        double t=T-H[i]*0.006;
        if(abs(near-A)>=abs(t-A)){
            near=t;
            ans=i+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}