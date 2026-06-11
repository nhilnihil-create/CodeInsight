#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,k,i,min;
  cin >> n >> k;
  k--;
  vector<int> h(n);
  for(i=0;i<n;++i)
  {
  cin >> h[i];
  }
  sort(begin(h),end(h));
  min=h[n-1]-h[0];
 
  
  
  for(i=0;i<n-k;i++)
  {
  if(h[i+k]-h[i]<min) min=h[i+k]-h[i];  
  }
  cout << min << endl;
return 0;
}