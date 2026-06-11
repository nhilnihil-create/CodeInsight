#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, seisu, marume;
  double avg;
  cin >> a;
  cin >> b;
  avg = (a + b)/2.0;
  seisu = (a + b)/2;
  marume = (avg - seisu)*2;
  cout << seisu+marume << endl;
}