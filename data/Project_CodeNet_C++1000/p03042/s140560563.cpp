#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int n;
  cin>>n;
  int y=n%100;
  int x=n/100;
  if(x==0&&1<=y&&y<=12){
    cout<<"YYMM"<<endl;
  }
  else if(0<x&&x<13&&y==0){
    cout<<"MMYY"<<endl;
  }
  else if(1<=x&&x<=12&y>=13){
    cout<<"MMYY"<<endl;
  }
  else if(x>=13&&1<=y&&y<=12){
    cout<<"YYMM"<<endl;
  }
  else if(1<=x&&x<=12&&1<=y&&y<=12){
    cout<<"AMBIGUOUS"<<endl;
  }
  else cout<<"NA"<<endl;
}