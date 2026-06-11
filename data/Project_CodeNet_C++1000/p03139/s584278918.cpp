#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,a,b;
  cin >>n >>a>>b;
  int x=0;
  if (a+b-n>0){
   x=a+b-n;
  }
  cout<<min(a,b)<<" "<<x<<endl;
}