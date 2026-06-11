#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
  int N;
  cin >> N;
  bool a = false;
  for(int i=0; i<100; i++) {
    for(int j=0; j<100; j++) {
      if(4*i + 7*j == N) a = true;
    }
  }
  if(a) cout << "Yes" << endl;
  else cout << "No" << endl;
}