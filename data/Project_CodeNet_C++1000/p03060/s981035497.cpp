#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,ans=0;
  cin >> n;
  vector<int> v(n),c(n);
  for (int i=0;i<n;i++){
    cin >> v[i+1];
  }
  for (int i=0;i<n;i++){
    cin >> c[i+1];
    if (v[i+1]-c[i+1] > 0){
      ans+=v[i+1]-c[i+1];
    }
  }
  cout << ans << endl;
}