#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, m, c;
  cin >> n >> m >> c;
  
  int b[m];
  for (int i = 0; i < m; i++)
    cin >> b[i];
  
  int a[m];
  int count = 0;
  for (int i = 0; i < n; i++) {
    
    for (int j = 0; j < m; j++)
      cin >> a[j];
    
    int sum = 0;
    for (int j = 0; j < m; j++)
      sum += a[j] * b[j];
    sum += c;
      
    if (sum > 0)
      count ++;
  }
  
  cout << count << endl;      
  
}