#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  int train = min(A, B);
  int bus = min(C, D);

  cout << train + bus << endl;
}