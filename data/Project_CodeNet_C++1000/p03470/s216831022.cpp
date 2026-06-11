#include <bits/stdc++.h>
using namespace std;
int main(void)
{
  long long int n,i,line,count=0;
  cin >> n;
  vector <int> d(n);
  for(i=0;i<n;i++)
  {
    cin >> d[i];
  }
  sort(d.begin(), d.end());
  line = d[0];
  count++;
  for(i=1;i<n;i++)
  {
    if(d[i] > line)
    {
      line = d[i];
      count++;
    }
  }
  cout << count;
  return 0;
}