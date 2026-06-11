#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N, K;
  cin >> N >> K;

  cout << (N % K != 0 ? '1' : '0') << endl;
}