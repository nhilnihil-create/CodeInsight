#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, k;
  cin >> a >> b >> k;
  
  vector<int> ans;
  for (int i=1 ; i<=min(a, b) ; i++){
    if (a%i==0 && b%i==0)
      ans.push_back(i);
  }
  
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  
  cout << ans.at(k-1) << endl;
}