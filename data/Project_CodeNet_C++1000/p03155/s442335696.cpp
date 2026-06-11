#include<iostream>
using namespace std;
int main(){
  int n,h,w,h_num=0,w_num=0;
  cin>>n>>h>>w;
  h_num = n-h+1;
  w_num = n-w+1;
  cout<<h_num * w_num<<endl;
}