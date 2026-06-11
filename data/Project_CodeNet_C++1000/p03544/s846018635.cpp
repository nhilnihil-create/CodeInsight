#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
 int n;
 cin >> n;
 vector<ll> l(n+1);
 l[0]=2;
 l[1]=1;
 if(n==1){
   cout << 1 << endl;
   return 0;
 }
 if(n>1){
   rep(i,n-1) l[i+2]=l[i]+l[i+1];
 }
  
 cout << l[n] << endl;
 return 0;
}
 
