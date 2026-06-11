#include<iostream>
#include<string>
#define rep(i, n) for (int i = 0; i < (n); i ++)
using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  
  int min = 1001;
  int m;
  int donuts;
  rep(i, n)
  {
    cin >> m;
    x -= m;
    donuts ++;
    if (m < min) min = m;
  }
  
  donuts += x / min;
  cout << donuts;
  return 0;
}
