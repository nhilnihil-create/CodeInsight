#include<iostream>
#include<string>
using namespace std;

int main()
{
  int n;
  cin >> n;
  
  double sum = 0;
  double amount;
  string currency;
  for (int i = 0; i < n; i ++)
  {
    cin >> amount;
    cin >> currency;
    if (currency == "JPY")
      sum += amount;
    else
      sum += amount * 380000.0;
  }
  
  cout << sum << endl;
  return 0;
}