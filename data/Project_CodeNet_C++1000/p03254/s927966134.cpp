#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, X, Sum=0;
  cin >> N >> X;
  vector<int> A(N);
  rep(i, N) cin >> A.at(i);
  sort(A.begin(), A.end());
  rep(i, N){
    X-=A.at(i);
    if(i!=N-1 && X>=0) Sum++;
    else if(i==N-1 && X==0) Sum++;
    else break;
  }
  cout << Sum << endl;
}