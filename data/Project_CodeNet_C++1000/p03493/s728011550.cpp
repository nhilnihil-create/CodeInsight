#include <bits/stdc++.h>
using namespace std;

int main() {
  int S;
  cin >> S;

  int S1, S2, S3;
  S1 = S / 100; 
  S2 = (S % 100) / 10;
  S3 = S % 10;
    
  cout << S1 + S2 + S3 << endl;

}
  
 