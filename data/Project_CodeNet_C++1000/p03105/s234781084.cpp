#include <iostream>

using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;

  if(a * c <= b)  cout << c << endl;

  if(a * c > b)
  {
    if(b < a)
    {
      cout << 0 << endl;
      goto exit;
    }
    cout << (b / a) << endl;
  }
  exit:
  ;
}