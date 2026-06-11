#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >>n;
  int t[111100],x[111100],y[111100];
  t[0]=x[0]=y[0]=0;
  bool a=true;
  for(int i=1;i<=n;i++)cin >> t[i] >> x[i] >> y[i];
  for(int i=1;i<=n;i++){
    int t1=t[i]-t[i-1];
    int a1=abs(x[i-1]-x[i])+abs(y[i-1]-y[i]);
    
    if(t1<a1){
      a=false;
    }
    if(t1%2!=a1%2){
      a=false;
    }
  }
  if(a)cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}