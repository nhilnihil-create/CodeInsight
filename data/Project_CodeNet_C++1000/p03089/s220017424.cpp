#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> a,b(n);
  for(int i=0; i<n; i++) cin>>b[i];
  for(int i=n-1; i>=0; i--){
    if(b[i]==i+1) {
      a.push_back(b[i]);
      b.erase(b.begin()+i);
      i = b.size();
    }
  }
  if(b.size() != 0) {
    cout<<-1;
    return 0;
  }
  reverse(a.begin(),a.end());
  for(int i=0; i<a.size(); i++) cout<<a[i]<<endl;
}