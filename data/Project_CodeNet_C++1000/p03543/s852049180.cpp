#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,X1,X2,X3,X4;
  cin>>N;
  X1=N/1000;
  X2=(N-X1*1000)/100;
  X3=(N-X1*1000-X2*100)/10;
  X4=(N-X1*1000-X2*100-X3*10)/1;
  if(X2==X3){if(X2==X1||X2==X4){cout<<"Yes"<<endl;} else{cout<<"No"<<endl;}}
  else{cout<<"No"<<endl;}
}