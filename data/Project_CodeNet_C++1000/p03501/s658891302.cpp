#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int t, a, b;
  cin >> t >> a >> b;
  int planA = t * a;
  int planB = b;
  if (planA == planB || planA < planB) {
    cout << planA;
  } else {
    cout << planB; 
  }
}