#include<bits/stdc++.h>
using namespace std;
int main(){
  int s,n,m;
  cin>>s;
  n=s/100;
  m=s%100;
  if(1<=n && n<=12 && 1<=m && m<=12) cout<<"AMBIGUOUS"<<endl;
  else if(1<=m && m<=12) cout<<"YYMM"<<endl;
  else if(1<=n && n<=12) cout<<"MMYY"<<endl;
  else cout<<"NA"<<endl;
}