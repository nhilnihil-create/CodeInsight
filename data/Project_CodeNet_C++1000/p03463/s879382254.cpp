#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  
  int dist = B-A-1;
  
  if(dist % 2==0) cout << "Borys" << endl;
  else cout << "Alice" << endl;
}