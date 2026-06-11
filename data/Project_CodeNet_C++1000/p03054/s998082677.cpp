#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003;

int main(){
    
    int H,W,N;cin>>H>>W>>N;
    int s,t;cin>>s>>t;
    string S,T;cin>>S>>T;
    vector<int> U(N),D(N),L(N),R(N);
    bool flag=true;
    int u=0,d=0,l=0,r=0;
    for(int i=N-1;i>=0;i--){
        if(i!=N-1){
            if(T[i]=='U') d--;
            if(T[i]=='D') u--;
            d=max(d,0);
            u=max(u,0);
        }
        if(S[i]=='U') u++;
        if(S[i]=='D') d++;
        U[i]=u;
        D[i]=d;
    }
    if(U[0]>=s||(H-s+1)<=D[0]) flag=false;
    for(int i=1;i<N;i++){
        if(U[i]+D[i]>H) flag=false;
        if(U[i]==H||D[i]==H) flag=false;
    }
    
    for(int i=N-1;i>=0;i--){
        if(i!=N-1){
            if(T[i]=='L') r--;
            if(T[i]=='R') l--;
            r=max(r,0);
            l=max(l,0);
        }
        if(S[i]=='L') l++;
        if(S[i]=='R') r++;
        L[i]=l;
        R[i]=r;
    }
    if(L[0]>=t||(W-t+1)<=R[0]) flag=false;
    for(int i=1;i<N;i++){
        if(L[i]+R[i]>W) flag=false;
        if(L[i]==W||R[i]==W) flag=false;
    }
    
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    /*for(int i=0;i<N;i++){
        cout<<U[i]<<" "<<D[i]<<" "<<L[i]<<" "<<R[i]<<endl;
    }*/
}
