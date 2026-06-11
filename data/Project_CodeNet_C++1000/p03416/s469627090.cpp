#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,n,s=0;
  cin>>A>>B;
  n=A;
  while(n<=B){
    if(n%10==n/10000&&n/10%10==n/1000%10) s+=1;
    else s+=0;
    n+=1;
  }
  cout<<s<<endl;
}