#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1000000007;

int main() {
  int A,B,C;
  cin >> A >> B >> C;
  if(A==B)
    cout << C << endl;
  else if(B==C)
    cout << A << endl;
  else
    cout << B << endl;
}