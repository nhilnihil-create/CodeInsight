#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,k;cin>>a>>b>>c>>k;
  cout<<a+b+c+max({a,b,c})*(pow(2,k)-1);
}