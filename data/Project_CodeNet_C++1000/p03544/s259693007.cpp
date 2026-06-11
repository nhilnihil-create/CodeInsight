#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int64_t m2,m1;
  m2 = 2LL;
  m1 = 1LL;
  
  for (int i=0;i<N-1;i++){
    m2 += m1;
    swap(m1,m2);
  }
  
  cout << m1 << endl;
}
