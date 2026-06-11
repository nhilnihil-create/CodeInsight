#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >>a>>b;
  int s=a+b;
  
  if(s%2==1) cout <<s/2+1<<endl;
  else if(s%2==0) cout <<s/2<<endl;
  
  return 0;
}
