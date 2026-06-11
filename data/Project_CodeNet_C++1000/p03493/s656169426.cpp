#include <bits/stdc++.h>
using namespace std;

int main() {
  int S1S2S3;
  cin >> S1S2S3;
  cout << S1S2S3 / 100 + ( S1S2S3 - S1S2S3 / 100 * 100 ) / 10
    + ( ( S1S2S3 - S1S2S3 / 100 * 100 )
       - ( S1S2S3 - S1S2S3 / 100 * 100 ) / 10 * 10 ) << endl;
}