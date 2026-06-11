#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a;
  cin>> n >> a;
  int ans;
  ans=n%500;
  if(ans==0){
  cout<<"Yes"<<endl;
  }
  if(ans!=0){
  if(ans<=a){
  cout<<"Yes"<<endl;}
  else{
  cout<<"No"<<endl;}}
}