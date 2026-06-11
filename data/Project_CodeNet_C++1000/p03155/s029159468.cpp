#include <iostream>

using namespace std;

int main()
{
  int n,h,w;
  cin >> n;
  cin >> h;
  cin >> w;
  h=(n-h+1);
  w=(n-w+1);
  cout << h*w;
  return 0;
}