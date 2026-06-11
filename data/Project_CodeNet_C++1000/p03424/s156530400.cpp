#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int j = 0;
  for (int i; i < N; i++){
    string color;
    cin >> color;
    if (color == "Y")
      j++;
  }
  if (j > 0)
    cout << "Four" << endl;
  else
    cout << "Three" << endl;
}