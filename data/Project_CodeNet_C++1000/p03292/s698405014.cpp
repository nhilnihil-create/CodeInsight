#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main(){
  vector<int> a(3);
  for (int i=0 ; i<3 ; i++)
    cin >> a.at(i);
  
  int n;
  vector<int> ans;
  for (int i=0 ; i<3 ; i++){
    for (int j=0 ; j<3 ; j++){
      if (i==j)
        continue;
      n = abs(a.at(j)-a.at(i)) + abs(a.at(3-i-j)-a.at(j));
      ans.push_back(n);
    }
  }
  
  sort(ans.begin(), ans.end());
  cout << ans.at(0) << endl;
}