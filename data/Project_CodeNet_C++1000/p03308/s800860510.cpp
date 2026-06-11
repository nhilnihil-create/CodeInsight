#include<iostream>
#define rep(i, n) for (int i = 0; i < (n); i ++)
using namespace std;

int main()
{
  int n;
  cin >> n;
  
  int max = 0, min = 1000000001;
  int tmp;
  rep(i, n)
  {
    cin >> tmp;
    if (tmp > max) max = tmp;
    if (tmp < min) min = tmp;
  }
  
  cout << max - min;
  return 0;
}
