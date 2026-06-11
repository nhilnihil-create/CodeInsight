#include <iostream>
#include <string>
using namespace std;
int main()
{
  string S;
  cin >> S;
  int s[3] = {0};
  for (long i = 0; i < S.length(); i++) {
    switch (S[i]) {
      case 'a':
        s[0]++;
        break;
      case 'b':
        s[1]++;
        break;
      case 'c':
        s[2]++;
        break;
    }
  }
  if (s[0]==1&&s[1]==1&&s[2]==1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
