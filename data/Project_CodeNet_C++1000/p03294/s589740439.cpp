#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  long long int a[3005],sum=0;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    sum=sum+a[i]-1;
  }
  cout<<sum<<endl;
}
