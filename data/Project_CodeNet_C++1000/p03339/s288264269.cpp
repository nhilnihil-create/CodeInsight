#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll N;  cin>>N;
    string S;   cin>>S;
    vector<ll> countW(N,0);
    vector<ll> countE(N,0);
    for(int i=1;i<N;i++){   //左にあるWの数を累積和
        if(S[i-1]=='W'){
            countW[i]=countW[i-1]+1;
        }
        else{
            countW[i]=countW[i-1];
        }
    }
    for(int i=N-2;i>=0;i--){
        if(S[i+1]=='E'){
            countE[i]=countE[i+1]+1;
        }
        else{
            countE[i]=countE[i+1];
        }
    }
    ll ans=99999999;
    for(int i=0;i<N;i++){
        ans=min(ans,countW[i]+countE[i]);
    }
    cout<<ans;
    return 0;
}