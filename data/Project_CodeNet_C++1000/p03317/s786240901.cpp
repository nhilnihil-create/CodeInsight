#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N,K; cin>>N>>K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++){
        cin>>A[i];
    }
    
    if(N==K){
        cout<<1<<endl;
        return 0;
    }else if(K==2){
        cout<<N-1<<endl;
        return 0;
    }else{
        ll ans=N/(K-1);
        if(N%(K-1)>1) ans++;
        cout<<ans<<endl;
    }
}
    