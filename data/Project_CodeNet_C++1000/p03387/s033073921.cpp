#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)

int main(){
  vector<int> vec(3);
  cin >> vec[0] >> vec[1] >> vec[2];
  
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  
  int A,B,C;
  A = vec[0];
  B = vec[1];
  C = vec[2];
  
  int n,t;
  n = A-B;
  t = B-C;
  
  if(t%2 == 0) cout << n + t/2 << endl;
  else cout << n + t/2 + 2 << endl;
}
