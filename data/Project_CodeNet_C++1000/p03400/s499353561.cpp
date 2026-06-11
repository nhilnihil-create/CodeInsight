#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,d,x;
  cin>>n>>d>>x;
  vector<int> a(n);
  for(int i = 0;i<n;i++) cin>>a[i];
  int c = 0;
  for(int i = 0;i<n;i++)
  {   int j = 0;
     
      while(j*a[i]+1<=d) j++;
      c+=j;
   
  }
  cout<<c+x<<endl;
}