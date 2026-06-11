#include <iostream>
using namespace std;

int main()
{
  string ans[] = {"No", "Yes"};
  int a, b, c;
  cin >> a >> b >> c;
  
  cout << ans[(a==b&&a==c)];
  
  return 0; 
}