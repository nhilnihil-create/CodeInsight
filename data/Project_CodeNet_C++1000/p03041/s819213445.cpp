#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  int a,b;
  char c;
  string s;
  cin>>a>>b;
  cin>>s;
  int i,n;
  n=s.size();
  for(i=0;i<n;i++)
  {
    if(i!=b-1){cout<<s[i];}
    else{c=s[i]-'A'+'a';cout<<c;}
  }
}
 