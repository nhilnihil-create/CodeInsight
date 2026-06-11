#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,k; cin>>a>>b>>k;
  vector<int> v;
  for(int i=min(a,b); i>0; i--) if(!(a%i||b%i)) v.push_back(i);
  cout<<v[k-1];
}