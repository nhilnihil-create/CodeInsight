#include<iostream>
using namespace std;

int main()
{
  int x;
  cin >> x;
  
  cout << "Christmas ";
  for (int i = 25; i > x; -- i)
    cout << "Eve ";
  
  cout << endl;
  return 0;
}
