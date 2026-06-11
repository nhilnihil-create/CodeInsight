#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  int sum=0;
  cin >> N >> X;
  
  vector <int> m(N);
  
  for (int i=0; i<N; i++){
    cin >> m[i];
    sum += m[i];
  }
  
  sort (m.begin(), m.end());
  
  X = X - sum;
  int num = N + X/m[0];
  
  cout << num << endl;
 
        
  
}