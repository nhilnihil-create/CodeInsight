#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
  vector<int> A(3);
  rep(i, 3) cin >> A.at(i);
  
  sort(A.begin(), A.end());
  cout << (A.at(2) - A.at(1)) + (A.at(1) - A.at(0)) << endl;
}