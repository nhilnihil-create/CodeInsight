#include<bits/stdc++.h>
using namespace std;
int main(){
  string x,y;
  cin>>x>>y;
  int u=0;
  for(int i=0;i<3;i++){
    if(x[i]==y[2-i])u++;
  }
  if(u==3)cout<<"YES";
  else cout<<"NO";
}