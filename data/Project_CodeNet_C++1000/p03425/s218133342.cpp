#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;

int main(){
  ll N;
  cin >> N;
  ll M,A,R,C,H;
  M=0;
  A=0;
  R=0;
  C=0;
  H=0;
  rep(i, N){
    string S;
    cin >> S;
    
    if(S[0] =='M') M++;   
    if(S[0] =='A') A++;
    if(S[0] =='R') R++;
    if(S[0] =='C') C++;
    if(S[0] =='H') H++;
  }
  
  vector<ll> V = {M, A, R, C, H};
  
  ll ans = 0;
  
 for(int i = 0; i<3; i++){
   for(int j = i+1; j<4; j++){
     for(int k = j+1; k<5; k++){
       ans += V[i]*V[j]*V[k];
     }
   }
 }
 
  cout << ans << endl;
}


