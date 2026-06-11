#include <bits/stdc++.h>
using namespace std;

int main(){
  int i,n,k;
  i=1;
  cin>>n>>k;
  while(n>0){
    if(i<k) i +=i;
    else i +=k;
    n--;
  }
  cout<<i<<endl;
}