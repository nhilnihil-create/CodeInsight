#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,K; cin >> N >> K;
    long long ans=0;
    for(int i=1;i<=N;i++){
        ans+=max(0,i-K)*(N/i);
        ans+=max(N-(N/i)*i-K+1,0);
    }
    if(K==0) ans-=N;
    cout << ans << endl;
}