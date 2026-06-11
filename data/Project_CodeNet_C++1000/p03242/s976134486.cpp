#include <iostream>
#include <string>
using namespace std;
int main()
{
  string S;
  cin >> S;
  for (int i = 0; i < S.length(); i++) {
    if (S[i]=='1') cout << "9";
    else if (S[i]=='9') cout << "1";
    else cout << S[i];
  }
  cout << endl;
  return 0;
}
