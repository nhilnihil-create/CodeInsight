#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N,K;
  cin >> N >> K;

  int x = 1;
  rep(i,N) x = min(x * 2, x + K);

  cout << x << endl;
}
