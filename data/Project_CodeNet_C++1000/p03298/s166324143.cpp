#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    int N;
    string S;cin>>N>>S;
    map<pair<string,string>,ll> M;
    
    for(int bit=0;bit<(1<<N);bit++){
        string A,B;
        for(int i=0;i<N;i++){
            if(bit&(1<<i)) A+=S[i];
            else B+=S[i];
        }
        M[make_pair(A,B)]++;
    }
    
    ll ans=0;
    
    for(int bit=0;bit<(1<<N);bit++){
        string A,B;
        for(int i=0;i<N;i++){
            if(bit&(1<<i)) A+=S[2*N-1-i];
            else B+=S[2*N-1-i];
        }
        if(M[make_pair(A,B)]) ans+=M[make_pair(A,B)];
    }
    
    cout<<ans<<endl;
    
    
}


