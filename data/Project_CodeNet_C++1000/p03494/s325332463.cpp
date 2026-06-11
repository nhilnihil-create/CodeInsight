#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  int count = 0;
  int ans = 0;
  int a;
  for (int i=0; i<N; i++) {
    cin >> a;
    while ( a%2 == 0) {
      a /= 2;
      count++;
    }
    if (i == 0) {
      ans = count;
    }
    if (count < ans) {
      ans = count;
    }
    count = 0;
  }
  cout << ans << endl;
}