#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,k;
  vector<int> v;
  cin>>a>>b>>k;
  int m=min(a,b);
  for(int i=1;i<=m;i++){
    if(a%i==0 && b%i==0) v.push_back(i);
  }
  sort(v.begin(),v.end(),greater<int>());
  cout<<v[k-1];

}
