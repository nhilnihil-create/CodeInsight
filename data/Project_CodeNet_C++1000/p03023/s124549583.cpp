#include <iostream>

using namespace std;

int main()
{
  int N;
  cin >> N;
  
  int result{180};
  for (int i = 3; i < N; i++) {
    result += 180;
  }
  
  cout << result << endl;
}