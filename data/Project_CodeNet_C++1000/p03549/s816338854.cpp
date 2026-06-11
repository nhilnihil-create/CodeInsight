#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,m;
  cin>>n>>m;
  long long kotae=0;
  int kakeru=1;
  for(int i=1;i<=m;i++)kakeru*=2;
  //cout<<kakeru<<endl;
  kotae=((n-m)*100+1900*m)*kakeru;
  cout<<kotae<<endl;
  return 0;
}