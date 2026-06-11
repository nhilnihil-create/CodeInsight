#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for(int i = 0; i < n; ++i) cin >> a[i];
  
  sort(a.begin(), a.end());
  
  int sum = 0;
  int num = 0;
  for(int i = 0; i < n; ++i)
  {
    sum += a[i];
    if(sum < x)
    {
      num++;
    }
    else if(sum == x)
    {
      num++;
      break;
    }
    else
    {
      break;
    }
  }
  if(sum < x) num--;
  cout << num << endl;
}
