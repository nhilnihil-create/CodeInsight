#include <bits/stdc++.h>
using namespace std;

int main(){
  int A1,A2,A3;
  cin >> A1 >> A2 >> A3;

  int upper= max(A1, max(A2, A3));
  int lower= min(A1, min(A2, A3));
  
  cout << upper- lower << endl;
}