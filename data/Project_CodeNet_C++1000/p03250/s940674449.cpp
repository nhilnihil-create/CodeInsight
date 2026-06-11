#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
  vector<int> c(3);
  int i = 0;
  for (int i = 0; i < 3; i ++)
    cin >> c.at(i);
  
  sort(c.begin(), c.end(), greater<>());
  cout << c.at(0) * 10 + c.at(1) + c.at(2) << endl;
  
  return 0;
}
