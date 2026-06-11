#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  map<int,int> a;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    a[x]++;
  }
  int c=0;
  for(auto x:a)
    c+=(x.first<=x.second?x.second-x.first:x.second);
  cout<<c<<endl;
}