#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, d;
  cin >> n;
  
  vector<int> diam(n);
  for(int i = 0; i < n; i++){
    cin >> d;
    diam.at(i) = d;
  }
  
  sort(diam.begin(), diam.end());
  
  int count = 1;
  for(int j = 0; j < n - 1; j++){
    if(diam.at(j) != diam.at(j + 1)) count++;
  }
  cout << count << endl;
}