#include <bits/stdc++.h>
using namespace std;

int main()
{
 int n;
  cin >> n;
  vector<int> a;
  double ave = 0;
  for (int i = 0;i < n;i++)
  {
   int tmp;
    cin >> tmp;
    a.push_back(tmp);
    ave += tmp;
  }
  ave /= n;
  
  double mn = 1000;
  int idx = 0;
  for (int i = 0; i < n; i++)
  {
    if (abs(ave-a[i]) < mn)
    {
      mn = abs(ave-a[i]);
      idx = i;
    }
  }
  cout << idx << endl;
}