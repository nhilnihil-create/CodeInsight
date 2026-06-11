#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      ans+=(4*i+7*j==n);
    }
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}