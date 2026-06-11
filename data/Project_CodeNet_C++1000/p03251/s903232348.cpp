#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vector<int> vecA(N);
  vector<int> vecB(M);
  rep(i, N) {
    cin >> vecA.at(i);
  }
  rep(i, M) {
    cin >> vecB.at(i);
  }
  sort(vecA.begin(), vecA.end());
  sort(vecB.begin(), vecB.end());
  reverse(vecA.begin(), vecA.end());
  if(vecA.at(0) >= vecB.at(0)) {
    cout << "War" << endl;
    
  }
  else if(X < vecB.at(0) && vecA.at(0) < Y){ 
    cout << "No War" << endl;
  }
  else {
    cout << "War" << endl;
  }
}
