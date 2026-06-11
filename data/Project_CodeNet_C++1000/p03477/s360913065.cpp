#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

bool is_it_a_num(char a) {
  if (a == '0') return true;
  if (a == '1') return true;
  if (a == '2') return true;
  if (a == '3') return true;
  if (a == '4') return true;
  if (a == '5') return true;
  if (a == '6') return true;
  if (a == '7') return true;
  if (a == '8') return true;
  if (a == '9') return true;
  else return false;
}

int main(){ 
  int A, B, C, D, l, r;
  
  cin >> A >> B >> C >> D;
  l = A + B;
  r = C + D;
  
  if (l > r) cout << "Left" << endl;
  if (l == r) cout << "Balanced" << endl;
  if (l < r) cout << "Right" << endl;
}
