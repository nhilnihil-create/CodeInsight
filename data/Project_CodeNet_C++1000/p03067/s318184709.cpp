#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  cin >> A >> B >> C;
  
  vector<int> D = {A,B,C};
  sort(D.begin(),D.end());
  if ( D.at(1) == C )
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}