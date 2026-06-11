#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,k; cin>>a>>b>>k;
  vector<int> v;
  for(int i=0; i<k; i++){
    if(a+i<=b) v.push_back(a+i);
    if(a<=b-i) v.push_back(b-i);
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  for(int i:v) cout<<i<<endl;
}