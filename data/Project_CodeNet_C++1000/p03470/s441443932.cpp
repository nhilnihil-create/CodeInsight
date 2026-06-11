#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> d(n);
  for (int i = 0; i < n;i++){
    cin >> d.at(i);
  }
  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());
  
  int step = 0;
  for(int i = 0; i < n; i++){
    if(i != 0 && d[i] == d[i - 1]){ 
      continue;
    }
    step++;
  }
  cout << step << endl;
}