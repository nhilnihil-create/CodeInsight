#include <bits/stdc++.h>
using namespace std;
int main(void)
{
  int n,x,i,count=0,bit=0;
  cin >> n >> x;
  vector<int> s(n);
  for(i=0;i<n;i++)
  {
    cin >> s[i];
  }
  for(i=0;i<n;i++)
  {
    x -= s[i];
    count++;
  }
  sort(s.begin(),s.end());
  while (x >= s[0])
  {
    x -= s[0];
    count++;
  }
  
  cout << count;
  return 0;
}