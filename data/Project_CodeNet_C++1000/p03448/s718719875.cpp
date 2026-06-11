#include <iostream>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
  int a , b, c , x;
  cin >> a >> b >> c >> x;
  int sum = 0;
  for(int A = 0;A <= a;A++){
    for(int B = 0;B <= b;B++){
      for(int C = 0;C <= c;C++){
        int X = 500*A + 100*B + 50*C;
        if(X == x)sum++;
      }
    }
  }
  cout << sum << "\n";
}

