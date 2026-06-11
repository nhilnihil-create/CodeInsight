#include <bits/stdc++.h>
using namespace std;

int main() {
  int s1s2s3;
  cin >> s1s2s3;
  cout << s1s2s3/100+(s1s2s3/10-s1s2s3/100*10)
    +(s1s2s3-s1s2s3/100*100-(s1s2s3/10-s1s2s3/100*10)*10)
    << endl;
}