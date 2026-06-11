#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll= long long;
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<ll>M(5,0);
    string S;
    rep(i,N){
        cin>>S;
        if(S[0]=='M'){
            M[0]++;
        }
        else if(S[0]=='A'){
            M[1]++;
        }
        else if(S[0]=='R'){
            M[2]++;
        }
        else if(S[0]=='C'){
            M[3]++;
        }
        else if(S[0]=='H'){
            M[4]++;
        }
    }
    ll sum=0;
    rep(i,3){
        for(int j=i+1;j<4;j++){
            for (int k=j+1;k<5;k++){
                sum+=(ll) M[i]*M[j]*M[k];
            }
        }
    }
    cout<<sum<<endl;
    
    }
    
    
  
 
 


