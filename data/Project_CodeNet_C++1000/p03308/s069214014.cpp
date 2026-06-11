#include <bits/stdc++.h>
using namespace std;
     
int main() {
  int n, max=0, min=0;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  
  max = *max_element(A.begin(), A.end());
  min = *min_element(A.begin(), A.end());
  
  cout << max-min << endl;
}