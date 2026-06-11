#include<bits/stdc++.h>
using namespace std;

int f(int n){
  if(n%2==0)
    return n/2;
  return n*3+1;
}
int main(){
  int n;
  cin >> n;
  map<int,int>deta;
  deta[n]=1;
  bool no=true;
  int ans=1,m=n;
  while(no){
    ans++;
    m=f(m);
    if(deta[m]==1)
      no=false;
    else
      deta[m]=1;
  }
  cout << ans << endl;
  return 0;
}