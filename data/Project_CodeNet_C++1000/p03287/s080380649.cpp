#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  map<int,int64_t> r;
  r[0]++;
  int s=0;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    s=(s+a)%m;
    r[s]++;
  }
  int64_t c=0;
  for(auto x:r)
    c+=x.second*(x.second-1)/2;
  cout<<c<<endl;
}