#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int X,Y,A,ans;
  cin >>X>>Y;
  int flag=0;
  A=X;ans=1;
  while(true){
    A*=2;
    if(A>Y){break;}
    else{
    ans++;
    }
  }  
  cout<<ans;
}

