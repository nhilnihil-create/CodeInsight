#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int N,X;
  cin >> N >> X;
  
  vector<int> m(N);
  for(int i=0; i<N; i++){
    cin >> m.at(i);
  }
  
  int sumg=X;
  for(int i=0; i<N; i++){
    sumg -= m.at(i);
  }
  
  sort(m.begin(),m.end());
  
  int cnt = N;
  for(int i=0; i<N; i++){
    int a = 0;
    a = sumg / m.at(i);
    sumg -= a * m.at(i);
    cnt += a;
  }
  
  cout << cnt << endl;
}