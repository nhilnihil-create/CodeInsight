#include <iostream>
using namespace std;
#include<vector>
int main()
{
  int n,k;
  cin>>n>>k;
  const int INF=1e9+7;
  vector<long long int>h(n);
  for(int i=0;i<n;i++){
    cin>>h[i];}

  vector<long long int> s(n,INF);
  s[0]=0;
  for(long long int i=0;i<n;i++)
  {
    for(long long int j=i+1;j<=i+k;j++)
    {
      if(j<n)
      s[j]=min(s[j],s[i]+abs(h[j]-h[i]));
    }
 }
 cout<<s[n-1];
 return 0;
}
