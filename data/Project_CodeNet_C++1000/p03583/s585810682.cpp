#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  
  for(int i = 1; i < 3501; i++){
    for(int j = i; j < 3501; j++){
      long long now = n * i * j;
      long long c = 4 * i * j - n * i - n * j;
      if(c <= 0) continue;
      if(now % c ) continue;
      cout << i << " " << j << " " << now / c << endl;
      return 0;
    }
  }
}