#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int N;
  cin >> N;

  if (N % 2 == 0)
    cout << (N / 2) * (N / 2) << endl;
  else
    cout << (N / 2) * ((N / 2) + 1) << endl;
}