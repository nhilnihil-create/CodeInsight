#include<iostream>
using namespace std;

int main()
{
  int k;
  cin >> k;
  int n = k / 2;
  if(k % 2)
  {
    cout << n * (n + 1) << endl;
  }
  else
  {
    cout << n * n << endl;
  }
}