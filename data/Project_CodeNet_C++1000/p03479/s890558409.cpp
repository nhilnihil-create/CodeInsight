#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  
  ll X,Y,count=0,z,i=0;
  cin >> X >> Y;
  
  while(X<=Y){
    X*=2;
    count++;
  }
  
 /* z=Y/X;
  
  
  while(pow(2,i)<=z){
    i++;
    count++;
  }*/
  
  cout << count<< endl;
 
}


