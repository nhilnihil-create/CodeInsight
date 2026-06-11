#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    int N;cin>>N;
    vector<ll> A(N),B(N);
    for(int i=0;i<N;i++){
        cin>>A[i]>>B[i];
    }
    ll ans=0;
    
    vector<ll> S,T;
    
    for(int i=0;i<N;i++){
        if(A[i]<B[i]){
            ans+=B[i];
        }else if(A[i]==B[i]){
            S.push_back(B[i]);
        }else{
            T.push_back(B[i]);
        }
    }
    
    sort(all(S));
    sort(all(T));
    
    if(ans==0) cout<<0<<endl;
    else{
        for(int i=0;i<S.size();i++){
            ans+=S[i];
        }
        
        for(int j=1;j<T.size();j++){
            ans+=T[j];
        }
        
        cout<<ans<<endl;
    }
    
}


