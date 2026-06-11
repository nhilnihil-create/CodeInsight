#include<bits/stdc++.h>
using namespace std;
int main(){
  int r,d;
  cin>>r>>d;
  int x;
  cin>>x;
  int a=0;
  for (int i=1;i<=10;i++){
    a=r*x-d;
    cout<<a<<endl;
    x=a;
  }
}