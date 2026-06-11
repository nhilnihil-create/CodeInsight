#include <bits/stdc++.h>
using namespace std;

int main() { 
  int n, a, b;
  cin >> n >> a >> b;
  int total = 0;
  
  for (int i = 1; i <= n; i++) {
    string num = to_string(i);
    int sum = 0;
    
    for (int j = 0; j < (int)num.size(); j++) {
      sum += (int)(num.at(j) - '0');
    }
    
    if (sum >= a && b >= sum) total += i;
  }
  
  cout << total << endl;
}
