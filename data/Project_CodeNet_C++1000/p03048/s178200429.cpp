#include<bits/stdc++.h>
using namespace std;
int main(){
  int r,g,b,n,a=0,t;
  cin >> r >> g >> b >> n;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      t=n-r*i-g*j;
      if(t%b==0&&0<=t/b&&t/b<=n)a++;
    }
  }
  cout << a;
}
