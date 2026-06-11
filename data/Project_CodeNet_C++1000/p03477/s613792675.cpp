#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int A,B,C,D;
  cin >> A >> B >> C >> D;

  if (A+B>C+D) {
    cout << "Left" << endl;
  } else if (A+B==C+D) {
    cout << "Balanced" << endl;
  } else if (A+B<C+D) {
    cout << "Right" << endl;
  }
  return 0;
}
