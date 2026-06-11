#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
  int a, b, c, d, e, k;
  cin >> a >> b >> c >> d >> e >> k;
  
  if (e - a > k) cout << ":(" << endl;
  else cout << "Yay!" << endl;
  
  return 0;
}