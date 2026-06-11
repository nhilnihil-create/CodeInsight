#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int maxi=0,mini=10e9,baf;
  for(int i=0;i<n;i++){
    cin >> baf;
    mini=min(mini,baf);
    maxi=max(maxi,baf);
  }
  cout << maxi-mini << endl;
  return 0;
}