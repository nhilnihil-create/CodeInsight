#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b;
  cin>>n>>a>>b;
  int x;
  if(n*a>=b){
    x=b;
    cout<<x<<endl;
  }
  else{
    x=n*a;
    cout<<x<<endl;
  }
}