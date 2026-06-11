#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,x;
  cin>>n>>a>>x;
  for(int i=0; i<10; i++){
    x=x*n-a;
    cout<<x<<endl;
  }
  return 0;
}