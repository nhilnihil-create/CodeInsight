#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string C;

  for (int i = 0; i < N; i++)
  {
    cin >> C;

  	if (C == "Y")
      break ;
  }
  if (C == "Y")
    cout << "Four" << endl;
  else
    cout << "Three" << endl;
}
