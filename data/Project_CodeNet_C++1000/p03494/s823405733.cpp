#include <bits/stdc++.h>
using namespace std;

long long waru(long long x){
    long long y=0;
    while(x%2==0){
        y++;
        x/=2;
    }
    return y;
}

int main(void){
    long long N;cin>>N;
    long long A[N];
    long long ans=pow(10,9);
    for(long long i=0;i<N;i++){
        cin>>A[i];
        ans=min(waru(A[i]),ans);
    }
    cout<<ans<<endl;
    return 0;
}