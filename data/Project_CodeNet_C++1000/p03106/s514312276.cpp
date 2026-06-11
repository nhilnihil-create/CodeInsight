#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int a, b, k;
  cin >> a >> b >> k;
  vector<int> v;
  
  int maxval = min(a, b);
  for(int i=1; i<=maxval; i++)
  {
    if(a % i == 0 && b % i == 0)
      v.push_back(i);
  }
  
  cout << v[v.size()-k] << endl;
  return 0;
}