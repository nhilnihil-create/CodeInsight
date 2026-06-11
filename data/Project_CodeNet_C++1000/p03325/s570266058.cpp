#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  vector<int> a(n);
  for (int i=0; i<n; i++) cin>>a[i];
  
  int ans=0;
  for (auto d : a){
    while (d%2==0){
      d/=2;
      ans+=1;
    }
  }
  cout<<ans<<endl;
}