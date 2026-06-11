#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long int a,b,d=1;
  cin>>a;
  int c=1;
  for(int i=0;i<a;i++){
    cin>>b;
    if(b%2==0)d*=2;
    c*=3;
  }
  cout<<c-d;
}