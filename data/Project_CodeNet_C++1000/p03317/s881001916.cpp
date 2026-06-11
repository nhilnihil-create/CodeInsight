#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  int N, K;
  cin >> N >> K;
  N-=2;
  K--;
  cout << N/K+1 << endl;
}
