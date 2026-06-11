#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A, B;
  cin >> N >> A >> B;
  
  int min = N * A;
  
  if (min>B){
    min = B;
  }
  cout << min << endl;
}