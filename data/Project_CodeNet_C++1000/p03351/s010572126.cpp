#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d;cin>>a>>b>>c>>d;
  if(fabs(c-a)>d&&(fabs(a-b)>d||fabs(c-b)>d))cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}