#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,i,al,bo;
  al=0;
  bo=0;
  cin >> n;
vector<int> a(n);
  for(i=0;i<n;++i)
  {
  cin >> a.at(i);
  }
sort(a.begin(),a.end());
reverse(a.begin(),a.end());
  for(i=0;i<n;++i)
  {
  if(i%2==0) al=al+a.at(i);
  else bo=bo+a.at(i);
  }
cout << al-bo;
return 0;}