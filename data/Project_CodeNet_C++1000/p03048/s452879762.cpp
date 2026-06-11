#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll R,G,B,n;
  cin >> R >> G >> B >> n;
  ll i=0,j=0,a=0;
  
  while(R*i<=n){
    j=0;
    while(R*i+G*j<=n){
      if((n-R*i-G*j)%B==0){
        a++;
      }
      j++;
    }
    i++;
  }
  
  cout << a << endl;
}