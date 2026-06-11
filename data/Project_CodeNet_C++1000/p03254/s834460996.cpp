#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  
  vector<int> a(n);
  for (int i = 0; i < n; i ++)
    cin >> a.at(i);
  
  sort(a.begin(), a.end());
  
  int happy = 0;
  for (int i = 0; i < n; i ++)
  {
    if (x < a.at(i)) break;
    else if (i == n - 1 && a.at(i) != x) break;
    x -= a.at(i);
    happy ++;
  }
  
  cout << happy;
  
  return 0;
}