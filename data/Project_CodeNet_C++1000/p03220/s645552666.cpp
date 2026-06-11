#include <iostream>
#include <map>
using namespace std;

int main()
{
  int n, t, a;
  double minavr = 1000;
  map<double, int> avr;
  cin >> n >> t >> a;
  for(int i=0; i<n; i++)
  {
    int h;
    cin >> h;
    double tmp = abs(t - h * 0.006 - a);
    avr[tmp] = i+1;
    minavr = min(minavr, tmp);
  }
  
  cout << avr[minavr] << endl;
  return 0;
}