#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  vector<int> v;
  cin >> n;
  for(int i = 0; i < 4; i++)
  {
    int t = n % 10;
    v.push_back(t);
    n /= 10;
  }
  if((v[0]==v[1] && v[1]==v[2]) ||
    (v[1]==v[2]) && v[2]==v[3])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
  return 0;
}