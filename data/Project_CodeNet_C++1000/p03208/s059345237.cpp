#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  
  vector<int> hlist;
  
  for(int i = 0; i < n; i++){
    int h;
    cin >> h;
    hlist.push_back(h);
  }
  
  sort(hlist.begin(), hlist.end());

  int difference = 1000000000;
  int a = 0;
  
  for(int i = 0; i < n + 1 - k; i++){
    a = hlist[i + k - 1] - hlist[i];
    if (a < difference) difference = a;
  }
  cout << difference << endl;
}
