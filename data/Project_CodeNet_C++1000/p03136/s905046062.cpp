#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> l(n);
  for(int i=0; i<n; i++) cin >> l[i];
  
  vector<int>::iterator max_itr = max_element(l.begin(), l.end());
  int sum = 0;
  for(vector<int>::iterator it=l.begin(); it!=l.end(); it++)
  {
    if(it != max_itr)
      sum += *it;
  }
  
  if(*max_itr < sum)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}