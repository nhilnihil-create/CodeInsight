#include <bits/stdc++.h>
using namespace std;
int main(){
  int  a,s,d,f;
  cin>>a>>s>>d>>f;
  int total=0;
  if(a>=s)total+=s;
  else total+=a;
  if(d>=f)total+=f;
  else total+=d;
  cout<< total<<endl;
}
