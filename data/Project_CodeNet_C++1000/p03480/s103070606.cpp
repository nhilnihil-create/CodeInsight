#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
  char s[100000];
  cin>>s;
  int a[100000];
  int l=strlen(s);
  int ans=0;
  for(int i=0;i<l;i++)
  {
      if(s[i]!=s[i+1])
      {
          a[ans]=max(i+1,l-i-1);
          ans++;
      }
  }
  cout<<endl;
  int mini=l;
  for(int i=0;i<ans;i++)
  {
    mini=min(mini,a[i]);
  }
  cout<<mini<<endl;
}
