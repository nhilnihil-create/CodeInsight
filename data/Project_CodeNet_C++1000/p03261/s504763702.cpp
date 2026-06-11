#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> w(n);
  for (int i=0 ; i<n ; i++)
    cin >> w.at(i);
  
  int ans = 1;
  for (int i=0 ; i<n-1 ; i++){
    for (int j=i+1 ; j<n ; j++){
      if (w.at(i) == w.at(j)){
        ans = 0;
        break;
      }
    }
    if (w.at(i).at(w.at(i).size()-1) != w.at(i+1).at(0))
      ans = 0;
    if (ans == 0)
      break;
  }
  
  if (ans == 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}