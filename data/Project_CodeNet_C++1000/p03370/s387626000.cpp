#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,X;
  cin >> N >> X;
  int gram = 0;
  int count = 0;
    
  vector<int>m(N);
  for (int i = 0; i < N; i++) {
    cin >> m.at(i);
    gram += m.at(i);
    count++;
  }
  sort(m.begin(), m.end());
  count += (X-gram)/m.at(0);
  cout << count << endl;
}
  

