#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main(){
  ll n;
  cin >> n;
  vector<ll>x(n),y(n),h(n);
  for(int i=0; i<n; i++ ) cin >> x[i] >> y[i] >> h[i];
  
  for(int Y=0; Y<=100; Y++){
   for(int X=0;X<=100; X++){
     ll judge=-1;
     for(int i=0; i<n; i++){
       if(h[i]>0){
         ll tmp = pow(pow(X-x[i],2),0.5)+pow(pow(Y-y[i],2),0.5)+h[i];
         if(judge==-1){
           judge=tmp;
         }
         else{
           if(judge!=tmp) judge=-2;
         }
       }
     }
     
     if(judge==-2) continue;
     
     for(int i=0; i<n; i++){
       if(h[i]==0){
         if(judge>pow(pow(X-x[i],2),0.5)+pow(pow(Y-y[i],2),0.5)){
           judge=-2;
         }
       }
     }
     
     if(judge==-2) continue;
     cout << X << " " <<  Y << " " << judge << endl;
   } 
  }
}
  
  
  
