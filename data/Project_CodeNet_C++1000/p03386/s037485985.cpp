#include<iostream>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int A, B, K;
  cin >> A >> B >> K;

  rep(i,A,B) {
    if (i - A < K) cout << i << endl;
    else if (B - i < K) cout << i << endl;
  }
  return 0;
}
