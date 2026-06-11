#include <iostream>
using namespace std;

int main()
{
  int n,k;
  cin>>n>>k;
  
  int count = 0;
  for(int i=1;i<n+1;i++)
  {
    if(i+k <= n+1)
      count++;
    else
      break;
  }
  cout<<count<<endl;
  return 0;
}