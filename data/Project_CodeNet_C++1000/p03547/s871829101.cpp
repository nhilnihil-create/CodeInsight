#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < ((int)(n)); i++) // 0-indexed昇順

int main()
{
  char A,B;
  cin >> A >> B;
  if (A > B) {
    cout << ">" << endl;
  } else if (A < B) {
    cout << "<" << endl;
  } else {
    cout << "=" << endl;
  }
}