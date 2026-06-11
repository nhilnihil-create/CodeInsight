#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  int sum =0;
  bool ans = false;

  for(int i=0; i<N; i++) {
    cin >> L.at(i);
  }
  sort(L.begin(),L.end());
  reverse(L.begin(),L.end());
  
  for(int i=1; i<N; i++) sum += L.at(i);
  
  if(L.at(0)< sum) ans = true;

  if(ans == true) cout << "Yes" << endl;
  else cout << "No" << endl;
}