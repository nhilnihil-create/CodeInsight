#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
 int n,Y,y;
 cin >> n >> Y;
 y = Y/1000;
 
 for(int i=0; i<=n; i++){
   for(int j=0; j<=n-i; j++){
       int k=n-i-j;
       if(10*i+5*j+k==y){
         cout << i << " " << j << " " << k << endl;
         return 0;
       
     }
   }
 }
  
  cout << "-1 -1 -1" << endl;
  return 0;
}
