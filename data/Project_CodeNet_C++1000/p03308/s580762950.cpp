#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >>n;
  int dai=0;
  int shou=INT_MAX;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    dai=max(dai,x);
    shou=min(shou,x);
  }
  cout<<dai-shou<<endl;
  return 0;
}