#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, result;

  cin>>n;

  if(n%2 > 0)
    result = n*2;
  else
    result = n;

  cout<<result<<endl;

  return 0;
}