#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<vector<int>> c(3, vector<int>(3));
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      cin >> c[i][j];
  bool res = true;
  vector<int> a(3), b(3);
  // assuming a0 = 0
  for (int i = 0; i < 3; i++) { b[i] = c[0][i]; a[i] = c[i][i] - b[i];} 
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (a[i] + b[j] != c[i][j]) {res = false; break;}
  cout << (res ? "Yes" : "No") << endl;
}