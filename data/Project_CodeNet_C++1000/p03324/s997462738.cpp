#include<bits/stdc++.h>
using namespace std;
int main(){
  int d,n;
  cin>>d>>n;
  int p=1;
  for(int i=0;i<d;i++)
    p*=100;
  cout<<p*(n==100?101:n)<<endl;
}