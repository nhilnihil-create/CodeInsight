#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007;

int main(){
    
    int N;cin>>N;
    vector<ll> S(N);
    bool plus=false,minus=false;
    for(int i=0;i<N;i++){
        cin>>S[i];
        if(S[i]>0) plus=true;
        else if(S[i]<0) minus=true;
    }
    if(plus&&!minus){
        ll M=S[0];
        int pM=0;
        for(int i=0;i<N;i++){
            if(S[i]>M){
                M=S[i];
                pM=i;
            }
        }
        cout<<N-1<<endl;
        cout<<pM+1<<" "<<2<<endl;
        for(int i=1;i<N-1;i++){
            cout<<i+1<<" "<<i+2<<endl;
        }
    }else if(!plus&&minus){
        ll M=S[0];
        int pM=0;
        for(int i=0;i<N;i++){
            if(S[i]<M){
                M=S[i];
                pM=i;
            }
        }
        cout<<N-1<<endl;
        cout<<pM+1<<" "<<N-1<<endl;
        for(int i=N-1;i>1;i--){
            cout<<i<<" "<<i-1<<endl;
        }
    }else if(!plus&&!minus) cout<<0<<endl;
    else{
        ll M=abs(S[0]);
        int pM=0;
        for(int i=0;i<N;i++){
            if(abs(S[i])>M){
                M=abs(S[i]);
                pM=i;
            }
        }
        if(S[pM]>0){
            cout<<2*N-1<<endl;
            for(int i=0;i<N;i++){
                if(i!=pM) cout<<pM+1<<" "<<i+1<<endl;
            }
            cout<<pM+1<<" "<<pM+1<<endl;
            cout<<pM+1<<" "<<2<<endl;
            for(int i=1;i<N-1;i++){
                cout<<i+1<<" "<<i+2<<endl;
            }
        }else{
            cout<<2*N-1<<endl;
            for(int i=0;i<N;i++){
                if(i!=pM) cout<<pM+1<<" "<<i+1<<endl;
            }
            cout<<pM+1<<" "<<pM+1<<endl;
            cout<<pM+1<<" "<<N-1<<endl;
            for(int i=N-1;i>1;i--){
                cout<<i<<" "<<i-1<<endl;
            }
        }
    }
}
