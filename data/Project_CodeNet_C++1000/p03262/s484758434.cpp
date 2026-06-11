#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int N,X;cin>>N>>X;
    vector<int>x(N+1);
    x[0]=X;
    for(int i=1;i<=N;i++){
        cin>>x[i];
    }
    sort(x.begin(),x.end());
    int A[N];
    for(int i=0;i<N;i++){
        A[i]=x[i+1]-x[i];
    }
    long long ans=x[1]-x[0];
    for(int i=1;i<N;i++){
        ans=gcd(ans,A[i]);
    }
    cout<<ans<<endl;
    return 0;
}
