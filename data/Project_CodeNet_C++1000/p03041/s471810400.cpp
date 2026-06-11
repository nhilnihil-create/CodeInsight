#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,k;
  cin>>n>>k;
  char s[1000];
  for(int i=1;i<=n;i++)
  {
    cin>>s[i];
  }
  s[k]=s[k]+' ';
  for(int i=1;i<=n;i++)
  {
    cout<<s[i];
  }
}