#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> L(n + 1);
  for (int i = 0; i < n + 1; i++){
      if (i == 0)L[i] = 2;
      else if (i == 1)L[i] = 1;
      else{
          L[i] = L[i - 1] + L[i - 2];
      }
  }
  cout << L[n] << endl;
}
