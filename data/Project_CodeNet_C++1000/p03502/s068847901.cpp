#include <bits/stdc++.h>
using namespace std;

int f(int x){
  int ret=0;
  while(x>0){
    ret +=x%10;
    x /=10;
  }
  return ret;
  
}

int main(){
  int n; cin>>n;
  cout<<(n%f(n)? "No":"Yes")<<endl;
}