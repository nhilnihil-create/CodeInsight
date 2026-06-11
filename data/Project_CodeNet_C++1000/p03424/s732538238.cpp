#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  bool four = false;
  cin >> N;
 
  rep(i, N)
  {
    string S;
    cin >> S;
    if (S == "Y")
    {
        four = true;
    }
  }
  if (four)
  {
    cout << "Four" << endl;
  }else
  {
    cout << "Three" << endl;
  }
}