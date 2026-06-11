#include <iostream>

using namespace std;

int main()
{
  string S;
  cin >> S;
  
  int count = 0;
  for (auto c: S) {
    if (c == 'x') {
      count++;
    }
  }
  
  if (count >= 8) {
    cout << "NO" << endl;
  } else {
  	cout << "YES" << endl;
  }
  
}
