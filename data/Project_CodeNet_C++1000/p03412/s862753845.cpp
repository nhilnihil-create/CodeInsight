#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=301,INF=1<<30;

int main(){
    
    ll N;cin>>N;
    int ans=0;
    vector<int> A(N),B(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int j=0;j<N;j++){
        cin>>B[j];
    }
    int div=1;
    
    for(int k=1;k<=29;k++){
        div*=2;
        vector<int> C(N),D(N);
        for(int i=0;i<N;i++){
            C[i]=A[i]%div;
        }
        for(int i=0;i<N;i++){
            D[i]=B[i]%div;
        }
        sort(all(C));
        sort(all(D));
        
        ll cnt=0;
        
        for(int i=0;i<N;i++){
            auto left=lower_bound(all(D),div/2-C[i]);
            auto right=lower_bound(all(D),div-C[i]);
            cnt+=distance(left,right);
            left=lower_bound(all(D),div+div/2-C[i]);
            right=lower_bound(all(D),div+div-C[i]);
            cnt+=distance(left,right);
        }
        
        if(cnt%2!=0) ans+=div/2;
        //cout<<ans<<endl;
    }
    
    cout<<ans<<endl;
    
}
