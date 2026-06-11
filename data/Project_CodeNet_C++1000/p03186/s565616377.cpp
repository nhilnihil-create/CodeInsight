#include <iostream>
using namespace std;

int main() {
      int A, B, C;
      cin >> A >> B >> C;
      
      int count = 0;
      int anti = A + B + 1;

      if(anti < C) count += anti + B;
      else count += C + B;

      cout << count << endl;
}