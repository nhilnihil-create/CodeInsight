#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,sum1=0,sum2=0;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  for(int i=0;i<n;i++)
  {
    if(a[i]>b[i])
    {
      sum1+=a[i];
      sum2+=b[i];
    }
  }
  cout<<sum1-sum2<<'\n';
}