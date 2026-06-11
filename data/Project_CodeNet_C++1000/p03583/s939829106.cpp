#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n;
  cin >> n;
  
  for(int i=1; i<=3500; i++){
   for(int j=1; j<=3500; j++){
     if((4*i*j-n*i-n*j)==0)continue;
     if(n*i*j%(4*i*j-n*i-n*j)==0 && n*i*j/(4*i*j-n*i-n*j)>0){
      cout << i << " " << j << " " <<  n*i*j/(4*i*j-n*i-n*j) << endl;
      return 0;
     }
   }
  }
  
}