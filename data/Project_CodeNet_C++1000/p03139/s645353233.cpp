#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int minnum,maxnum;
  maxnum = min(b,c);
  if(a<b+c) minnum=b+c-a;
  else minnum=0;
  cout<<maxnum<<' '<<minnum<<endl;
}