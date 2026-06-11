#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  unsigned long long jpy = 0;
  double btc = 0;
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
  {
    double x;
    string u;
    cin >> x >> u;
    if(u == "JPY")
      jpy += x;
    else
      btc += x;
  }
  
  cout << fixed << setprecision(6) << (double)jpy + btc * 380000 << endl;
  return 0;
}