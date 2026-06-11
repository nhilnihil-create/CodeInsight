#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i=0; i<n; i++) cin >> vec.at(i);
  
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  
  int a = 0, b = 0;
  for (int i=0; i<n; i+=2) a += vec.at(i); 
  for (int i=1; i<n; i+=2) b += vec.at(i);
  cout << a-b << endl;}
