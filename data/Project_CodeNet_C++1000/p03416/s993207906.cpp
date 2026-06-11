#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, count = 0;
  cin >> A >> B;

  for (int i = A; i <= B; i++) {
    int x = i / 1000;
    int y = i - (i / 100)*100;
    int z = (y - (y / 10)*10)*10 + y / 10;

    if(x == z){
      count += 1;
    }
  }

  cout << count << endl;
  return 0;

}
