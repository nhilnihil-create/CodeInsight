#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, r = 0, b = 0;
  cin >> N;
  char c;
  for (int i = 0; i < N; i++)
  {
    cin >> c;
    c == 'R' ? r++ : b++;
  }
  cout << (r > b ? "Yes" : "No") << endl;
}