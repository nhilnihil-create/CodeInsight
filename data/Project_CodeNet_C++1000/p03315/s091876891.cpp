#include <string>
#include <iostream>
using namespace std;
int main()
{
  string S;
  cin >> S;
  int ans = 0;
  for (int i = 0; i < S.length(); i++) {
    if (S[i]=='+') ans++;
    if (S[i]=='-') ans--;
  }
  cout << ans << endl;
  return 0;
}