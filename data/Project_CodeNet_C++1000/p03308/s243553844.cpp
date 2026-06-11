#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i=0 ; i<n ; i++)
    cin >> a.at(i);
  
  int m = 0;
  for (int i=0 ; i<n-1 ; i++){
    for (int j=i+1 ; j<n ; j++){
      if (abs(a.at(i) - a.at(j)) > m)
        m = abs(a.at(i) - a.at(j));
    }
  }
  
  cout << m << endl;
}