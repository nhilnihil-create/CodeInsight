#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  bool ok = false;
  for (int i = 0; i <= N; i++)
    for (int j = 0; j <= N; j++)
	  	if (i * 4 + j * 7 == N) ok = true;
  cout << (ok ? "Yes" : "No") << endl;
}