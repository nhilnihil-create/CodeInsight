#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> l(n);
  for (int i=0;i<n;++i) cin >> l[i];
  
  int ans=0;
  int res=0;
  for (int i=0;i<n;++i){
    ans=max(ans,l[i]);
    res+=l[i];
  }
  res-=ans;
  if (ans<res) cout << "Yes" << endl;
  else cout << "No" << endl;
}