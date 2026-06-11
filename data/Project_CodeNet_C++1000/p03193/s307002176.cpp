#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,H,W,count=0;
  cin>>n>>H>>W;
  for(int i=0;i<n;i++){
    int h,w;
    cin>>h>>w;
    if(h>=H && w>=W) count++;
  }
  cout<<count<<endl;
}