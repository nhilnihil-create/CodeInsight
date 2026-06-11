#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  const char* yn[] = {"No", "Yes"};
  cout << yn[C <= A + B] << endl;
  return 0;
}
