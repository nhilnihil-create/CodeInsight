#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  int sum = 0;
  sum += min(A,B);
  sum += min(C,D);
  cout << sum << endl;
}
