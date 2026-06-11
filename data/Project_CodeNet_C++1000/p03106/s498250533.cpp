#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
  if(a%b==0)
    return(b);
  else
    return(gcd(b,a%b));
}

int main(){
  int a,b,k;
  cin >> a >> b >> k;
  
  int x=gcd(a,b);
  
  int answer;
  
  int j=0;
  for(int i=x;i>0;i--){
    if(x%i==0){
      answer=i;
      j++;
    }
    if(j==k)
      break;
  }
  cout << answer << endl;
}