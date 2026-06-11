#include <bits/stdc++.h>
using namespace std;

int main(){
  long long X,Y;
  cin>>X>>Y;
  int i=0;
  for(;X<=Y;i++)
    X*=2;
  cout<<i<<endl;
}