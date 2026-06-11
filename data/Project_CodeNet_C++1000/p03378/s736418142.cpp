#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,x;
  cin>>n>>m>>x;
  int y=x;
  vector<int> a(m);
  for(int i=0;i<m;i++){
    cin>>a[i];
  }
  int cost=0;
  for(int i=0;i<n-x;i++){
    y++;
    for(int j=0;j<m;j++){
    if(y==a[j]) cost++;
    }
  }
  int sum=0;
  y=x;
  for(int i=0;i<x;i++){
    y--;
    for(int j=0;j<m;j++){
    if(y==a[j]) sum++;
    }
  }
  cout<<min(sum,cost)<<endl;
}