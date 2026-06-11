#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int n,m;
  cin >> n>>m;
  vector<int> L(m);
  vector<int> R(m);
  for(int i=0;i<m;i++){
    cin >>L[i] >>R[i];

  }
  sort(L.begin(), L.end());
  sort(R.begin(), R.end());
  if(L[m-1] > R[0])cout << 0 << endl;
  else{cout << R[0] - L[m-1] + 1 << endl;}
}