#include<iostream>
using namespace std;

int main()
{
  int n, a;
  cin >> n >> a;
  
  if (a >= (n % 500)) cout << "Yes";
  else cout << "No";
  
  return 0;
}