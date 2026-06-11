#include <bits/stdc++.h>
using namespace std;

int main(){
  int r,D,x0;
  cin>>r>>D>>x0;
  int x1;
  for (int i=0; i<10; i++){
    x1=r*x0-D;
    cout<<x1<<endl;
    x0=x1;
  }
}