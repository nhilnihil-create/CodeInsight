#include <bits/stdc++.h>
using namespace std;
#include <stdio.h>
int main() {
  vector<int>a(3);
  for(int i; i<3; i++) cin >> a.at(i);
  sort ( a.begin(), a.end() );
  int pls = 0;
  for (int i; i<2; i++) pls += a.at(i+1)-a.at(i);
  cout << pls << endl;
}

