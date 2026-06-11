#include <bits/stdc++.h>
using namespace std;

int main() {
  int sum = 0;
  int count = 0;
  vector<int> v(5);
  for(int i=0; i<5; i++) {
    int a;
    cin >> a;
    sum += a;
    if(a%10 == 0) count++;
    v[i] = a%10;
  }
  sort(v.rbegin(), v.rend());
  
  for(int i=0; i<4-count; i++) sum += 10-v[i];
  cout << sum << endl;
  return 0;
}