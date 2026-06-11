#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  while(n){
    int m=sqrt(n);
    if(n==m*m)break;
    n--;
  }
  cout<<n;
}
